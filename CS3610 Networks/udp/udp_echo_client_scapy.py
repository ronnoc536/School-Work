#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
UDP_echo program
Solution using scapy
Solution
"""
import time
import sys
import statistics
from scapy.all import *  # type: ignore
from typing import Tuple, List

# https://scapy.readthedocs.io/en/latest/troubleshooting.html
conf.L3socket = L3RawSocket  # type: ignore
# sometimes needed for default gateway, and
# always for localhost, and
# sometimes not for remote.


def parse_args() -> Tuple[str, int, int, int]:
    """
    parses the 4 args:
    server_hostname, server_port, num_pings, timeout
    """
    server_hostname = sys.argv[1]
    server_port = int(sys.argv[2])
    num_pings = int(sys.argv[3])
    timeout = int(sys.argv[4])
    return (server_hostname, server_port, num_pings, timeout)


def net_stats(
    num_pings: int, rtt_hist: List[float]
) -> Tuple[float, float, float, float, float]:
    """
    Computes statistics for loss and timing.
    Mimicks the real ping's statistics.
    Check them out: `ping 127.0.0.1`
    See `man ping` for definitions.
    This is just a math function.
    Don't do any networking here.
    """
    loss = 0.0
    rtt_min = 0.0
    rtt_avg = 0.0
    rtt_max = 0.0
    rtt_mdev = 0.0

    loss = (num_pings - len(rtt_hist)) / num_pings
    loss = round(loss, 2) * 100

    if len(rtt_hist) > 0:
        rtt_min = min(rtt_hist)
        rtt_avg = statistics.mean(rtt_hist)
        rtt_max = max(rtt_hist)
        if len(rtt_hist) > 1:
            rtt_mdev = statistics.stdev(rtt_hist)

    return (loss, rtt_min, rtt_avg, rtt_max, rtt_mdev)


def main() -> None:
    SERVER_HOSTNAME, SERVER_PORT, NUM_PINGS, TIMEOUT = parse_args()
    SERVER_IP = conf.route.route(SERVER_HOSTNAME)[1]  # type: ignore
    message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {0} {time.asctime()}"
    print(f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {len(message)} bytes of data.")
    rtt_hist = []
    time_total = 0
    for i in range(NUM_PINGS):
        message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {i+1} {time.asctime()}"
        packet = IP(dst=SERVER_IP) / UDP(dport=SERVER_PORT, sport=7777) / message  # type: ignore
        start = time.time()
        data = sr1(packet, timeout=TIMEOUT, verbose=0)  # type: ignore
        end = time.time()
        if data is not None:
            data = data[Raw].load  # type: ignore
            rtt = round(end - start, 1) * 1000
            rtt_hist.append(rtt)
            time_total += int(rtt)
            if data[:4] == b"oops":
                print("Damaged packet")
            else:
                print(
                    f"{str(len(data))} bytes from {SERVER_HOSTNAME} ({str(SERVER_IP)}): ping_seq={i+1} time={int(rtt)} ms"
                )
        else:
            print("timed out")

    # Note: you will want exception handling for lost packets (think timeout).
    # round RTT the nearest 10ms before adding it to rtt_hist and displaying it

    # ping stats
    loss, rtt_min, rtt_avg, rtt_max, rtt_mdev = net_stats(
        num_pings=NUM_PINGS, rtt_hist=rtt_hist
    )
    print(f"\n--- {SERVER_HOSTNAME} ping statistics ---")
    print(
        f"{NUM_PINGS} packets transmitted, {len(rtt_hist)} received, {int(loss)}% packet loss, time {time_total}ms"
    )
    print(
        f"rtt min/avg/max/mdev = {int(rtt_min)}/{int(rtt_avg)}/{int(rtt_max)}/{int(round(rtt_mdev))} ms"
    )


if __name__ == "__main__":
    main()

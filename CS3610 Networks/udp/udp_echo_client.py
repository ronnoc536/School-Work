#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
UDP_echo program
Solution using python sockets
Student template
"""
import socket
import time
import sys
import statistics
from typing import Tuple, List


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


def create_socket(timeout: int) -> socket.socket:
    """Create IPv4 UDP client socket"""
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.settimeout(timeout)
    return client_socket


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
    loss, rtt_min, rtt_avg, rtt_max, rtt_mdev
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
    # Get IP from hostname
    SERVER_IP = socket.gethostbyname(SERVER_HOSTNAME)
    # Create the socket
    client_socket = create_socket(timeout=TIMEOUT)

    message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {0} {time.asctime()}"
    print(f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {len(message)} bytes of data.")
    rtt_hist = []
    time_total = 0
    for i in range(NUM_PINGS):
        try:
            message = f"PING {SERVER_HOSTNAME} ({SERVER_IP}) {i+1} {time.asctime()}"
            start = time.time()
            client_socket.sendto(message.encode(), (SERVER_IP, SERVER_PORT))
            data = client_socket.recv(1024)
            end = time.time()
            rtt = round(end - start, 2) * 1000
            rtt_hist.append(rtt)
            time_total += int(rtt)
            if data.decode()[:4] == "oops":
                print("Damaged packet")
            else:
                print(
                    f"{str(len(data))} bytes from {SERVER_HOSTNAME} ({str(SERVER_IP)}): ping_seq={i+1} time={int(rtt)} ms"
                )
        except (TimeoutError):
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

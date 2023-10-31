#!/usr/bin/python3
# -*- coding: utf-8 -*-

import socket
import threading
from typing import Optional
from typing import Tuple  # added this to fixe the tuple issue


def serve_client(client_socket: socket.socket) -> None:
    """
    1. receives from the client,
    2. extracts the hostname and port from its request,
    3. forwards the message unchanged to the remote,
    4. receives a response from the remote by calling receive_response,
    5. sends that message back to the client
    6. Close the out_socket at the end of the request
    """
    response = receive_header(client_socket)
    host_and_port = extract_hostname(response)
    if host_and_port is None:
        client_socket.close()
        return
    else:
        out_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        out_socket.connect(
            (socket.gethostbyname(host_and_port[0].decode()), host_and_port[1])
        )
        out_socket.send(response)
        new_response = receive_response(out_socket)
        client_socket.send(new_response)
        out_socket.close()
        client_socket.close()


def receive_header(sock: socket.socket) -> bytes:
    """
    receives from the socket until either:
    a HTTP header is received,
    or the socket is closed.
    """
    data_response = sock.recv(4096)
    while "HTTP" not in data_response.decode() and data_response != b"0":
        data_response = b""
        data_response = sock.recv(4096)
    return data_response


def extract_hostname(message: bytes) -> Optional[Tuple[bytes, int]]:
    """
    Extracts the hostname and port from the HTTP header's Host field,
    and returns them as a tuple (hostname, port).
    Does not decode the hostname (leaves it as bytes)
    If no port is specified, it assumes the port is 80
    If no hostname is present, it returns None
    """
    split_message = message.decode().split()
    for i in range(len(split_message)):
        if "Host:" in split_message[i]:
            if ":" in split_message[i + 1]:
                return (
                    split_message[i + 1].split(":")[0].encode(),
                    int(split_message[i + 1].split(":")[1].strip()),
                )
            else:
                return (split_message[i + 1].strip().encode(), 80)
    return None


def receive_response(out_socket: socket.socket) -> bytes:
    """
    Receives the messages from the out_socket,
    and sends them to the client_socket.
    Receives HTTP message from the out_socket
    (HTTP request must already be sent by caller)
    Receive until the content is fully transmitted
    Return the message in full
    """
    response_list = []
    while True:
        response = out_socket.recv(4096)
        if response == b"":
            break
        response_list.append(response)
        response = b""
    server_response = b"".join(response_list)
    return server_response


def main() -> None:
    """
    Creates the proxy server's main socket and binds to it.
    With each new client that connects,
    serves their requests.
    This one is done for you.
    """
    # create the server socket, a TCP socket on localhost:6789
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_sock.bind(("", 6789))

    # listen for connections
    server_sock.listen(20)

    # forever accept connections
    # thread list is never cleaned (this is a vulnerability)
    threads = []
    while True:
        client_sock, addr = server_sock.accept()
        threads.append(threading.Thread(target=serve_client, args=(client_sock,)))
        threads[-1].start()


if __name__ == "__main__":
    main()

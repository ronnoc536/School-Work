#!/usr/bin/python3


def hello(your_name: str) -> str:
    return "Hello " + your_name


if __name__ == "__main__":
    your_name = input("Enter your name:\n")
    print(hello(your_name))

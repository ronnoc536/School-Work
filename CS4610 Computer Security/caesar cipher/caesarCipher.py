#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Caesar Cipher
# https://www.nostarch.com/crackingcodes (BSD Licensed)

# The string to be encrypted/decrypted:
message: str = input("Enter a string to translate:\n")

# Whether the program encrypts or decrypts:
# Set to either 'encrypt' or 'decrypt'.
mode: str = input("encrypt or decrypt?\n")

# The encryption/decryption key:
key: int = int(input("What is your key?\n"))

# Every possible symbol that can be encrypted:
SYMBOLS: str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?."

# Stores the encrypted/decrypted form of the message:
translated: str = ""

for symbol in message:
    # Note: Only symbols in the `SYMBOLS` string can be encrypted/decrypted.
    if symbol in SYMBOLS:
        symbolIndex = SYMBOLS.find(symbol)

        # Perform encryption/decryption:
        if mode == "encrypt":
            translatedIndex = (symbolIndex + key) % len(SYMBOLS)
        elif mode == "decrypt":
            translatedIndex = (symbolIndex - key) % len(SYMBOLS)

        translated = translated + SYMBOLS[translatedIndex]
    else:
        # Append the symbol without encrypting/decrypting:
        translated = translated + symbol

# Output the translated string:
print(translated + "\n")

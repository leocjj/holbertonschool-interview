#!/usr/bin/python3
"""
0x09. UTF-8 Validation
A character in UTF-8 can be 1 to 4 bytes long.
The data set can contain multiple characters.
The data will be represented by a list of integers.
Each integer represents 1 byte of data.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    :param data: list of integers
    :return: True if data is a valid UTF-8 encoding, else return False.
    """

    data = [number & 0xFF for number in data]
    data_size = len(data)
    j = 0
    while j < data_size:
        if (data[j] & int('10000000', 2)) == 0:
            bytes_to_check = 0
        elif (data[j] & int('11100000', 2)) == int('11000000', 2):
            bytes_to_check = 1
        elif (data[j] & int('11110000', 2)) == int('11100000', 2):
            bytes_to_check = 2
        elif (data[j] & int('11111000', 2)) == int('11110000', 2):
            bytes_to_check = 3
        else:
            return False
        if bytes_to_check > data_size - 1 - j:
            return False
        for i in range(1, bytes_to_check + 1):
            if not (data[j + i] & int('11000000', 2)) == int('10000000', 2):
                return False
        j += bytes_to_check + 1
    return True

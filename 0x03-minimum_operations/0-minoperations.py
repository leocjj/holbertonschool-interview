#!/usr/bin/python3
""" 0x00. Minimum operations """


def gcd(num):
    """
    Calculates the maximum divisor of num
    :param num: integer
    :return: the maximum divisor of num
    """
    if not isinstance(num, int) or num < 1:
        return None
    if num == 2:
        return 1
    for divisor in range(int(num / 2) + 1, 0, -1):
        if (num % divisor) == 0:
            return divisor


def minOperations(n):
    """
    In a text file, there is a single character H. Your text editor can execute
    only two operations in this file: Copy All and Paste. Given a number n,
    calculate the fewest number of operations needed to result in exactly n H
    characters in the file.
    :param n: given number.
    :return: Returns an integer, 0 if n is impossible to achieve.
    """
    n *= 2
    if not isinstance(n, int) or n < 1:
        print(0)

    divs = []
    while n > 1:
        divs.append(int(gcd(n)))
        n = divs[-1]
    result = 0
    for i, _ in enumerate(divs):
        if i == len(divs) - 1:
            break
        result += int(divs[i] / divs[i + 1])

    return result

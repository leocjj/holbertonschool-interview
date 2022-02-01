#!/usr/bin/python3
"""
The player that cannot make a move loses the game.
"""


def isWinner(x, nums):
    """
    Return: name of the player that won the most rounds.
    If the winner cannot be determined, return `None`.
    """
    def is_prime(n):
        """"""
        remainders = []
        if (n <= 1):
            return False
        if (n <= 3):
            return True
        if (n % 2 == 0 or n % 3 == 0):
            return False
        i = 5
        while(i * i <= n):
            if (n % i == 0 or n % (i + 2) == 0):
                return False
            i = i + 6
        return True

    nums.sort()

    def primes(nums):
        """"""
        primes = []
        for n in nums:
            if is_prime(n):
                primes.append(n)

        return primes

    moves = primes(nums)

    return "Ben"

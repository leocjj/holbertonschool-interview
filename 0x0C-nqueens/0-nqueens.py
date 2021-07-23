#!/usr/bin/python3
"""Finds the number of queens that can be placed on a board
   without being under attack"""
import sys

N = sys.argv
if len(N) != 2:
    print("Usage: nqueens N")
    exit(1)
N = int(N[1])
if not isinstance(N, int):
    print("N must be a number")
    exit(1)
if N < 4:
    print("N must be at least 4")
    exit(1)


def under_attack(col, queens):
    return col in queens or \
           any(abs(col - x) == len(queens)-i for i, x in enumerate(queens))


def solve(n):
    solutions = [[]]
    for row in range(n):
        solutions = [solution+[i]
                     for solution in solutions
                     for i in range(N)
                     if not under_attack(i, solution)]
    return solutions


for answer in solve(N):
    A = list(enumerate(answer, start=0))
    i = 0
    for t in A:
        t = list(t)
        A[i] = t
        i += 1
    print(A)

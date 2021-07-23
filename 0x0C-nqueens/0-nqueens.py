#!/usr/bin/python3
""" nqueens problem """
from sys import argv


def init():
    nq = None
    if len(argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        nq = int(argv[1])
    except ValueError:
        print('N must be a number')
        exit(1)
    if not isinstance(nq, int):
        print('N must be a number')
        exit(1)
    if nq < 4:
        print('N must be at least 4')
        exit(1)
    return nq


def solve(N, i=0, a=[], b=[], c=[]):
    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                for solution in solve(N, i+1, a+[j], b+[i+j], c+[i-j]):
                    yield solution
    else:
        yield a


if __name__ == '__main__':
    nqueens = init()
    for solution in solve(nqueens):
        answer = [[col, row] for col, row in enumerate(solution)]
        print(answer)

#!/usr/bin/python3
""" nqueens problem. """
import sys


def solve(N, i=0, a=[], b=[], c=[]):
    """ Find partial solutions recursively """
    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                for solution in solve(N, i+1, a+[j], b+[i+j], c+[i-j]):
                    yield solution
    else:
        yield a


nq = None
if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)
try:
    nq = int(sys.argv[1])
except ValueError:
    print('N must be a number')
    exit(1)
if not isinstance(nq, int):
    print('N must be a number')
    exit(1)
if nq < 4:
    print('N must be at least 4')
    exit(1)

for sol in solve(nq):
    answer = [[col, row] for col, row in enumerate(sol)]
    print(answer)

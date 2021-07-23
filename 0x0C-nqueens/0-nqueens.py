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
    m = [[0 for j in range(nq)] for i in range(nq)]
    for k in m:
        print(k)
    return m, nq


def places(m, nqueens, row, col, value):
    # Clear column
    for i in range(nqueens):
        if i != row:
            m[i][col] = -1
    # Clear row
    for i in range(nqueens):
        if i != col:
            m[row][i] = -1
    # Clear diagonal / up
    for d in range(1, nqueens):
        if (row + d) < nqueens and (col + d) < nqueens:
            m[row + d][col + d] = -1
        else:
            break
    # Clear diagonal / down
    for d in range(1, nqueens):
        if (row - d) >= 0 and (col - d) >= 0:
            m[row - d][col - d] = -1
        else:
            break
    # Clear diagonal \ up
    for d in range(1, nqueens):
        if (row + d) < nqueens and (col - d) >= 0:
            m[row + d][col - d] = -1
        else:
            break
    # Clear diagonal / up
    for d in range(1, nqueens):
        if (row - d) >=0 and (col + d) < nqueens:
            m[row - d][col + d] = -1
        else:
            break


def iteration(m, nqueens):
    for col in range(nqueens):
        for row in range(nqueens):
            for col2 in range(nqueens):
                if m[row][col2] == 0:
                    m[row][col2] = -2                   # It's a Queen.
                    places(m, nqueens, row, col2, 1)    # And attacks this positions.
                    break


if __name__ == '__main__':
    m, nqueens = init()
    # iteration(m, 1, nqueens)
    iteration(m, nqueens)
    for i in m:
        print(i)

'''
ri = rj = 0
for ri in range(6):
    for rj in range(nqueens):
        if m[ri][rj] >= 0:
            m[ri][rj] = -2
            break
    # Clear column
    for i in range(nqueens):
        if i != ri:
            m[i][rj] = -1
    # Clear row
    for j in range(nqueens):
        if j != rj:
            m[ri][j] = -1
    # Clear diagonal / up
    for d in range(1, nqueens):
        if (ri + d) < nqueens and (rj + d) < nqueens:
            m[ri + d][rj + d] = -1
        else:
            break
    # Clear diagonal / down
    for d in range(1, nqueens):
        if (ri - d) < nqueens and (rj - d) < nqueens:
            m[ri - d][rj - d] = -1
        else:
            break
    # Clear diagonal \ up
    for d in range(1, nqueens):
        if (ri + d) < nqueens and (rj - d) < nqueens:
            m[ri + d][rj - d] = -1
        else:
            break
    # Clear diagonal / up
    for d in range(1, nqueens):
        if (ri - d) < nqueens and (rj + d) < nqueens:
            m[ri - d][rj + d] = -1
        else:
            break
'''
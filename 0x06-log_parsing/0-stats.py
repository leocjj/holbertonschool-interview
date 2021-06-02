#!/usr/bin/python3
"""Program that reads stdin line by line and computes metrics"""
from sys import stdin


statusCode = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
totalSize = 0


def printStat():
    """Function that print log accumulately"""
    print("File size: {}".format(totalSize))
    for x in sorted(statusCode.keys()):
        if statusCode[x]:
            print("{}: {}".format(x, statusCode[x]))


if __name__ == "__main__":
    ct = 0
    try:
        for y in stdin:
            try:
                item = y.split()
                totalSize += int(item[-1])
                if item[-2] in statusCode:
                    statusCode[item[-2]] += 1
            except:
                pass
            if ct == 9:
                printStat()
                ct = -1
            ct += 1
    except KeyboardInterrupt:
        printStat()
        raise
    printStat()

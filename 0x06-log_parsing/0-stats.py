#!/usr/bin/env python3
import sys
from collections import OrderedDict
"""
0x00. Minimum operations
Script that reads stdin line by line and computes metrics
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning.
"""


def print_stats(total_size, stats):
    print("File size: {}".format(total_size))
    for key, value in stats.items():
        if value > 0:
            print("{}: {}".format(key, value))

if __name__ == "__main__":
    total_size = 0
    stats = OrderedDict({'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0})
    try:
        for line in sys.stdin:
            arguments = line.split()
            #print(stats.keys())
            if len(arguments) >= 2 and arguments[-2] in stats:
                stats.update({str(arguments[-2]): stats.get(arguments[-2]) + 1})
                total_size += int(arguments[-1])
            print_stats(total_size, stats)
    except KeyboardInterrupt:
        print("Saliendo")
        raise

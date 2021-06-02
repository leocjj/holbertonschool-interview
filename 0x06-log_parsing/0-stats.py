#!/usr/bin/python3
import sys
"""
0x00. Minimum operations
Script that reads stdin line by line and computes metrics
Input: <IP> - [<date>] "GET /projects/260 HTTP/1.1" <stat code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning.
"""


def print_stats(size, stat):
    """
    Print these statistics from the beginning
    :param size: Total file size
    :param stat: dictionary with status code and counters.
    :return: None
    """

    print("File size: {}".format(size))
    for key, value in stat.items():
        if value > 0:
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    total_size = 0
    line_counter = 0
    stats = dict({'200': 0, '301': 0, '400': 0, '401': 0, '403': 0,
                 '404': 0, '405': 0, '500': 0})
    try:
        for line in sys.stdin:
            args = line.split()
            if len(args) >= 2 and args[-2] in stats:
                stats.update({str(args[-2]): stats.get(args[-2]) + 1})
                total_size += int(args[-1])
            line_counter += 1
            if line_counter == 10:
                print_stats(total_size, stats)
                line_counter = 0
    except KeyboardInterrupt:
        print_stats(total_size, stats)
        raise

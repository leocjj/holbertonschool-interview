#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4   # Correct answer is 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 9   # Correct answer is 6
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12   # Correct answer is 7
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = -1   # Correct answer is 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 0.1   # Correct answer is 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 0   # Correct answer is 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 1   # Correct answer is 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

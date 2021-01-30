#!/usr/bin/python3
""" 0x00. Lockboxes Task 0 """


def canUnlockAll(boxes):
    """  Determines if all the boxes can be opened. """
    list_of_unique_keys = set()
    keys = set(boxes[0])

    while True:
        temp = keys - list_of_unique_keys
        if not temp:
            return False
        keys = set()
        for i in temp:
            if 0 < i < len(boxes):
                list_of_unique_keys |= {i}
                keys |= set(boxes[i])
        if len(list_of_unique_keys) + 1 == len(boxes):
            return True

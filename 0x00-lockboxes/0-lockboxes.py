#!/usr/bin/python3
""" 0x00. Lockboxes Task 0 """


def canUnlockAll(boxes):
    """  Determines if all the boxes can be opened. """
    list_of_unique_keys = set()
    keys = set(boxes[0])

    while True:
        temp = keys - list_of_unique_keys
        # print(i, keys, list_of_unique_keys, temp)
        if not temp:
            return False
        keys = set()
        for i in temp:
            if 0 < i < len(boxes):
                list_of_unique_keys |= {i}
                keys |= set(boxes[i])
        if len(list_of_unique_keys) + 1 == len(boxes):
            return True


def canUnlockAll2(boxes):
    """  Determines if all the boxes can be opened. """
    list_of_unique_keys = set()

    for i, keys in enumerate(boxes):
        temp = set(keys)
        # print(i, keys, list_of_unique_keys, temp)
        if temp - list_of_unique_keys:
            list_of_unique_keys |= temp
        else:
            if len(list_of_unique_keys) + 1 == len(boxes):
                return True
            else:
                return False
        if len(list_of_unique_keys) + 1 == len(boxes):
            return True
    return False

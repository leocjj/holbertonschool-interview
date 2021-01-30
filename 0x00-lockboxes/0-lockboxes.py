#!/usr/bin/python3
""" 0x00. Lockboxes Task 0 """


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    :param boxes: list of lists of positive integers
    :return: True if all boxes can be opened, else return False
    """
    list_of_unique_keys = set()
    keys = set(boxes[0])
    len_boxes = len(boxes)

    while True:
        # Identify new keys found.
        new_keys = keys - list_of_unique_keys
        # If still in loop and no new keys found
        if not new_keys:
            return False
        keys = set()
        # For each new key found.
        for i in new_keys:
            # Only take in count usefull keys.
            if 0 < i < len_boxes:
                # Add key to list of unique keys.
                list_of_unique_keys |= {i}
                # With each key open the box and store keys found.
                keys |= set(boxes[i])
        # If all keys were found.
        if len(list_of_unique_keys) + 1 == len_boxes:
            return True

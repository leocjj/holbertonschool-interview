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
        # New keys found.
        new_keys = keys - list_of_unique_keys
        # If still in loop and no new keys found
        if not new_keys:
            return False
        keys = set()
        # For each new key found.
        for key in new_keys:
            # Only take in count usefull keys.
            if 0 < key < len_boxes:
                # Add key to list of unique keys.
                list_of_unique_keys |= {key}
                # With each key open the box and store the keys found.
                keys |= set(boxes[key])
        # If keys were found for all boxes.
        if len(list_of_unique_keys) + 1 == len_boxes:
            return True

#!/usr/bin/python3
"""
0x10. Rain
"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of wall
    with unit width 1, as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.
    :param walls: list of non-negative integers.
    :return: Integer indicating total amount of rainwater retained.
    """

    water = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water = water + (min(left, right) - walls[i])

    return water

#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
""" determines if all the boxes can be opened """
    check = [0]

    for i in check:
        for j in boxes[i]:
            if j not in check:
                check.append(j)

    if len(check) == (len(boxes) - 1):
        return True
    else:
        return False

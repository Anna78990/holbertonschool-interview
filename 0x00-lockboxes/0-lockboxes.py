#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """
    check = [0]
    indexes = []
    for n in range(0, len(boxes)):
        indexes.append(n)

    for i in check:
        try:
            for j in boxes[i]:
                if j not in check:
                    check.append(j)
        except IndexError as e:
            return False
    if sorted(check) == indexes:
        return True
    else:
        return False

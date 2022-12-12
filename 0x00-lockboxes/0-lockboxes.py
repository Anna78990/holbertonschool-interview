#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """
    check = [0]
    nombre = 0
    for n in range(0, len(boxes)):
        nombre += 1

    for i in check:
        try:
            for j in boxes[i]:
                if j not in check:
                    check.append(j)
        except IndexError as e:
            return False
    if len(check) == nombre:
        return True
    else:
        return False

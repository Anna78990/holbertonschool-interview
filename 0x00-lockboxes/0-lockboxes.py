#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened """
    check = [0]
    a = 0
    indexes = []
    for n in boxes:
        indexes.append(a)
        a += 1

    for i in check:
        try:
            for j in boxes[i]:
                if j not in check:
                    check.append(j)
        except IndexError as e:
            if check[-2] == indexes[-1]:
                return True
            else:
                return False
    if len(check) >= len(indexes):
        return True
    else:
        return False

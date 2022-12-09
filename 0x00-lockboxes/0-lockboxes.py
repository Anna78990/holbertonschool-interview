#!/usr/bin/python3
import sys

def canUnlockAll(boxes):
    check = []

    if len(boxes) == 0:
         return True
    for i in range(0, len(boxes)):
         check.append(0)
    recursiveCheck(boxes, 0, check)
    if 0 in check:
        return False
    else:
        return True

def recursiveCheck(*argv):
    cur = argv[1]
    if len(argv[0][cur]) > 0:
        for i in argv[0][cur]:
            if argv[2][i] == 1:
                continue
            else:
                argv[2][i] == 1
                recursiveCheck(argv[0], i, argv[2])

#!/usr/bin/python3

a = [1, 2, 3]
b = [1, 2]

a = ''.join(map(str, a))
b = ''.join(map(str, b))

print(a)
print(b)
print(b in a)

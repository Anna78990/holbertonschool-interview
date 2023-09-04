"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 2147483640
print(isinstance(n, int))

print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

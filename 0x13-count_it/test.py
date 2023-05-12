import requests


dic = {"a": 1, "c": 100, "d": 2, "b": 100}
dict_p = sorted(map(lambda x, y: [x, y], dic.values(), dic.keys()))

print(type(dict_p))

for i, a in dict_p:
    print(i, a)

print("---")
dict_pp = dict(dict_p)

for i, a in dict_pp.items():
    print(i, a)

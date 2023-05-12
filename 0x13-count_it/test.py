import requests

def sort_key(x):
    return (-x[0], x[1])

dic = {"a": 1, "c": 100, "d": 2, "b": 100}
dict_p = list(map(lambda x, y: [x, y], dic.values(), dic.keys()))
dic_p = sorted(dict_p, key=sort_key)


for i, a in dic_p:
    print(i, a)

print("---")


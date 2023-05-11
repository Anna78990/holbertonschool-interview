#!/usr/bin/python3
"""print the frequencities of given words"""
import requests


def recursion(subreddit, dic, after=""):
    """returns the title counts"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    p = {"after": after}
    res = requests.get(url, headers={'User-agent': 'your bot 0.1'}, params=p)
    if res.status_code == 404:
        return None
    after = res.json().get("data").get("after")
    for re in res.json().get("data").get("children"):
        title = re.get("data").get("title").split(' ')
        title_lowercase = list(map(lambda x: x.lower(), title))
        for a in title_lowercase:
            if a in dic.keys():
                dic[a] += 1
    if after is not None:
        recursion(subreddit, dic, after)
        return


def count_words(subreddit, word_list):
    """prints the title counts"""
    lower = list(map(lambda x: x.lower(), word_list))
    li = sorted(set(lower))
    d = dict(map(lambda x: [x, 0], li))
    recursion(subreddit, d)
    for k, v in d.items():
        if v != 0:
            print('{}: {}'.format(k, v))

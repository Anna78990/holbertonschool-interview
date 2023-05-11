import requests

subreddit= "programming"
url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
res = requests.get(url, headers={'User-agent': 'your bot 0.1'})
if res.status_code == 404:
    print("o")
else:
    print("ok")

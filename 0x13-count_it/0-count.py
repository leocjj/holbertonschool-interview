#!/usr/bin/python3
"""
0x13. Count it!
"""

import requests
'''
https://towardsdatascience.com/how-to-use-the-reddit-api-in-python-5e05ddfd1e5c
def count_words(subreddit, word_list, count=0, other=0):
    pass

r = requests.get(r'http://www.reddit.com/user/spilcm/comments/.json')
data = r.json()
print(data.keys())
pass

# CLIENT_ID refers to 'personal use script' and SECRET_TOKEN to 'token'
# auth = requests.auth.HTTPBasicAuth('<CLIENT_ID>', '<SECRET_TOKEN>')
auth = requests.auth.HTTPBasicAuth('', '')

# here we pass our login method (password), username, and password
data = {'grant_type': 'password',
        'username': 'leocjj',
        'password': ''}
# setup our header info, which gives reddit a brief description of our app
headers = {'User-Agent': 'MyBot/0.0.1'}
# send our request for an OAuth token
res = requests.post('https://www.reddit.com/api/v1/access_token',
                    auth=auth, data=data, headers=headers)
# convert response to JSON and pull access_token value
TOKEN = res.json()['access_token']
# add authorization to our headers dictionary
headers = {**headers, **{'Authorization': f"bearer {TOKEN}"}}
# while the token is valid (~2h) we just add headers=headers to our requests
me = requests.get('https://oauth.reddit.com/api/v1/me', headers=headers)
res = requests.get("https://oauth.reddit.com/r/python/hot", headers=headers)
res2 = res.json()['data']['children']
pass
'''

def count_words(subreddit, wlist, after="", counting={}):
    """
    recursive function
    queries Reddit API
    parses the title of all hot articles
    prints a sorted count of given keywords
        (case-insensitive, delimited by spaces. Javascript should count as
        javascript, but java should not)

    If word_list contains the same word (case-insensitive)
        the final count should be the sum of each duplicate (example below)
    Results
        printed in descending order, by the count,
        and if the count is the same for separate keywords
            they should then be sorted alphabetically (ascending, from A to Z)
        Words with no matches should be skipped and not printed.
        Words must be printed in lowercase.

    Results are based on the number of times a keyword appears,
        not titles it appears in.
        java java java counts as 3 separate occurrences of java.
    To make life easier, java. or java! or java_ should not count as java
    If no posts match or the subreddit is invalid, print nothing.
    NOTE: Invalid subreddits may return a redirect to search results.
        Ensure that you are NOT following redirects.
    """

    if after is None:
        return []
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {"User-Agent": "Python3"}
    if after:
        url += '?after={}'.format(after)
    r = requests.get(url, headers=headers, allow_redirects=False)
    if str(r) != '<Response [200]>':
        return None
    data = r.json().get('data')
    after = data.get('after')
    children_list = data.get('children')
    for child in children_list:
        title = child.get('data').get('title')
        for word in wlist:
            ocurrences = title.lower().split().count(word.lower())
            if ocurrences > 0:
                if word in counting:
                    counting[word] += ocurrences
                else:
                    counting[word] = ocurrences
    if after is not None:
        return count_words(subreddit, wlist, after, counting)
    else:
        if not len(counting) > 0:
            return
        iterator = sorted(counting.items(),
                          key=lambda kv: (-kv[1], kv[0]))
        for key, value in iterator:
            print('{}: {}'.format(key.lower(), value))

import collections

dp = collections.defaultdict(lambda : collections.defaultdict(lambda: collections.defaultdict(int)))

dp['a']['b']['c']= 1

print(dp['a']['b']['c'])
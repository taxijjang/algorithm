from queue import PriorityQueue

def solution(genres,plays):
    janru = {}
    song = {}

    for i in range(len(genres)):
        if not bool(janru.get(genres[i])) :
            janru[genres[i]] = plays[i]
            song[genres[i]] = PriorityQueue()
            song[genres[i]].put((-plays[i],i))
        else:
            janru[genres[i]] += plays[i]
            song[genres[i]].put((-plays[i],i))

    janru = dict(sorted(janru.items(), key =(lambda janru: janru[1]),reverse=True))

    answer = []

    for name in janru:
        print(name)
        for cnt in range(2):
            if song[name].empty():
                break
           answer.append((song[name].get())[1])
    return answer
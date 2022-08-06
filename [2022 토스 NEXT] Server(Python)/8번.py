import queue
import time
import threading

sema = threading.Semaphore(1)
class Foo:
    def __init__(self):
        self.work = queue.Queue()
        self.lock = threading.Lock()

    def we(self) -> None:
        self.lock.acquire()
        self.work.put(1)
        print('we', end='')
        self.lock.release()


    def never(self) -> None:
        self.lock.acquire()
        self.work.put(1)
        print('never', end='')
        self.lock.release()

    def giveup(self) -> None:
        self.lock.acquire()
        self.work.put(1)
        print('giveup', end='')
        self.lock.release()


###################
# 수정하지 말아주세요! #
###################
import sys
import threading

for line in sys.stdin:
    methods = eval(line)
    break
f = Foo()
threads = []
for m in methods:
    threads.append(threading.Thread(target=getattr(f, m)))
for t in threads:
    t.start()
for t in threads:
    t.join()

class Queue:
    def __init__(self):
        self.inbox = []
        self.outbox = []
    
    def queue(self, x):
        self.inbox.append(x)
    
    def dequeue(self):
        if len(self.outbox) == 0:
            while (len(self.inbox)!= 0):
                self.outbox.append(self.inbox.pop())
        return self.outbox.pop()

temp = Queue()
temp.queue(3)
temp.queue(4)
print(temp.dequeue())
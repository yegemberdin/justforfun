class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        self.items.append(item)

    def addRear(self, item):
        self.items.insert(0,item)

    def removeFront(self):
        return self.items.pop()

    def removeRear(self):
        return self.items.pop(0)

    def size(self):
        return len(self.items)
d=Deque()
print(d.isEmpty())
d.addRear(2)
d.addRear(1)
d.addFront(3)
d.addFront(4)
print(d.size())
print(d.isEmpty())
d.addRear(-1)
print(d.removeRear())
print(d.removeFront())
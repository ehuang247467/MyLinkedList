class MyLinkedList:
    def __init__(self):
        self.head = self.Node(None)
        self.tail = self.Node(None)
        self.head.setNext(self.tail)
        self.tail.setNext(None)
        self.size = 0

    def length(self):
        return self.size

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")
        returnNode = self.getNth(index)
        return returnNode.getData()
    
    def add(self, data, index=None):
        if data == None:
            raise ValueError("Data cannot be None")
        if index == None:
            index = self.size
        if index < 0 or index > self.size:
            raise IndexError("Index out of bounds")
        curNode = self.head
        for i in range(index):
            curNode = curNode.getNext()
        nextNode = curNode.getNext()
        curNode.setNext(self.Node(data))
        curNode.getNext().setNext(nextNode)
        self.size += 1

    def set(self, data, index):
        if data == None:
            raise ValueError("Data cannot be None")
        if index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")
        setNode = self.getNth(index)
        toReturn = setNode.getData()
        setNode.setData(data)
        return toReturn

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")
        prevNode = self.head
        for i in range(index):
            prevNode = prevNode.getNext()
        curNode = prevNode.getNext()
        prevNode.setNext(curNode.getNext())
        self.size -= 1
        return curNode.getData()

    def clear(self):
        self.head.setNext(self.tail)
        self.size = 0

    def isEmpty(self):
        if self.size == 0:
            return True
        return False

    def getNth(self, index):
        if index < 0 or index >= self.size:
            raise ValueError
        curNode = self.head.getNext()
        for i in range(index):
            curNode = curNode.getNext()
        return curNode

    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

        def setNext(self, next):
            self.next  = next

        def setData(self, data):
            self.data = data

        def getNext(self):
            return self.next

        def getData(self):
            return self.data
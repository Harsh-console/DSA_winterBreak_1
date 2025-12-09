INF = 1000000000
class Stack:
    def __init__(self, max_Elements, ):
        self.max = max_Elements
        self.arr = []
    def push(self, x):
        if(not self.isFull()):
            self.arr.append(x)
        else:
            raise RuntimeError(" Stack Overflow ")
    def pop(self):
        if(not self.isEmpty()):
            temp = self.arr.pop(-1)
            return temp
        else:
            raise RuntimeError(" Stack Underflow ")

    def isEmpty(self): # returns True is stack is empty and False if it is not empty
        return (len(self.arr) == 0)
    def isFull(self): # returns True if stack is full and False if it is not full
        return(len(self.arr) >= self.max)
    def peek(self):
        if(not self.Empty()):
            return self.arr[-1]
        else:
            raise RuntimeError(" cannot peak to empty stack ")

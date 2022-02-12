class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.prev=None


class doublylist:
    def __init__(self):
        self.head=None
    
    
    def push(self,data):
        new_node = Node(data)
        new_node.next=self.head
        new_node.prev=None
        if self.head is not None:
            self.head.prev=new_node    
        self.head = new_node
    
    def printlist(self):
        temp = self.head
        while temp:
            print(temp.data,end='->')
            temp=temp.next
  
l = doublylist()
l.push(50)
l.push(40)
l.push(30)
l.push(20)
l.push(10)
l.printlist()

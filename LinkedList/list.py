class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head=None

    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data,end="->")
            current=current.next
    
n = int(input("Enter the value of n:\n"))
l = []
for i in range(n):
    k = int(input())
    l.append(k)
llist = LinkedList()
llist.head = Node(l[0])
llist2 = Node(l[1])
llist.head.next = llist2
llist3 = Node(l[2])
llist2.next=llist3
llist.print_list()

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class linked_list:
    def __init__(self):
        self.head=None
    def add_at_beginning(self,data):
        new_node = Node(data)
        new_node.next=self.head
        self.head=new_node
    def print_list(self):
        current=self.head
        while current is not None:
            print(str(current.data)+"->",end='')
            current =current.next
l=[40,30,20,10,5]
llist = linked_list()
llist.head = Node(50)
for i in l:
    llist.add_at_beginning(i)
llist.print_list()

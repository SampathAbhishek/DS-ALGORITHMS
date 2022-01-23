#Insertion of nodes at various positions in a singly linked list
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class linked_list:
    def __init__(self):
        self.head=None
    
    #Insertion of a node at the beginning
    def push(self,data):
        new_node = Node(data)
        new_node.next=self.head
        self.head=new_node
    
    #Insertion of a node after a given previous node
    def append(self,prev_node,data):
        if prev_node is None:
            print('The previous node is not present in Linked List')
        
        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next=new_node
        
    #Insertion of a node at the end    
    def last(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node  
        last = self.head 
        while last.next:
            last = last.next   
        last.next = new_node
    

    def print_list(self):
        current = self.head
        while current is not None:
            print(str(current.data)+"->",end='')
            current=current.next
llist = linked_list()
llist.push(10)
llist.push(40)
llist.append(llist.head.next,30)
llist.last(50)
llist.print_list()

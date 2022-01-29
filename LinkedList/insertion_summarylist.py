#Singly Linked List
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class Linked_List:
    def __init__(self):
        self.head=None
    
    #Insertion at beginning
    def push(self,data):
        new_node = Node(data)
        new_node.next=self.head
        self.head=new_node
        
    #Insertion Before a given position    
    def insert_after(self,prev,data):
        if prev is None:
            print('prev not found in Linked List')
            
        new_node = Node(data)
        new_node.next=prev.next
        prev.next=new_node
    
    #Reversing a linked list
    def reverse_list(self):
        prev = None
        next = None
        cur = self.head
        while cur is not None:
            next=cur.next
            cur.next=prev
            prev=cur
            cur=next
        
        self.head=prev
       
   #deleting a linked list given the value i.e. self.data
    def delete_node(self,data):
        temp = self.head
        if temp is not None:
            if temp.data == data:
                self.head= temp.next
                temp=None
                return
        while(temp):
            if temp.data == data:
                break
            else:
                prev = temp
                temp=temp.next
        
        if(temp==None):
            return
        prev.next = temp.next
        temp=None
             
               
    #Insertion at end
    def append(self,data):
        new_node = Node(data)
        if self.head is None:
            self.head=new_node
            return
        cur = self.head
        while(cur.next):
            cur=cur.next
        cur.next=new_node
        
    #print a linked list
    def print_list(self):
        cur = self.head
        while(cur):
            print(str(cur.data)+"->",end='')
            cur=cur.next
llist = Linked_List()
llist.append(10)
llist.append(20)
llist.push(5)
llist.insert_after(llist.head.next,15)
llist.print_list()
llist.reverse_list()
print()
llist.print_list()
llist.delete_node(20)
print()
llist.print_list()

#inner class in python

#There are two ways of acheiving this :-
#1. Creating an object inide the outer class
#2.Creating an object outside the outer class using the outer class name


class Student:
    def __init__(self,name,rollno):
        self.name = name
        self.rollno = rollno
        self.laptop = self.Laptop()# by creating an object inside outer class

    def show(self):
        print(self.name,self.rollno)
        self.laptop.show()

    class Laptop:
        def __init__(self):
            self.lname = "HP"
            self.modelno = "1#4389"
        def show(self):
            print(self.lname,self.modelno)


st1 = Student("Sampath Abhishek",35)
st2 = Student("Surya Srikhar",21)

st1.show()
st2.show()

#2nd method craeting object outside the outer class using the outer class name.
lap1 = Student.Laptop()
lap1.show()

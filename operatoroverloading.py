#Operator Overloading(OOPS CONCEPT--- in python)
class Student:
    def __init__(self,m1,m2):
        self.m1=m1
        self.m2=m2
    def info(self):
        print(self.m1,self.m2)
    def __add__(self,other):
        self.m1 = self.m1 + other.m1
        self.m2 = self.m2 + other.m2
        s3 = Student(self.m1,self.m2)
        return(s3)
    def __gt__(self,other):
        if (self.m1 + self.m2) > (other.m1 + other.m2):
            return True
        else:
            return False
s1 = Student(9,76)
s2 = Student(36,99)

s3 = s1 + s2 # can be treated as Student.__add__(s1,s2)
s3.info()

if s1 > s2:  #can be treated as Student.__gt__(s1,s2)
    print("s1 is topper")
else:
    print("s2 is topper")

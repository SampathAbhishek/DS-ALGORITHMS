#Method 1
#greatest common divisor

# Algorithm:-(A Systemetic procedure to acheive a task)
# step 1: Use fm,fn for list of factors m,n respectively
# step 2: for each i from 1 to m add i to fm,if i divides fm
# step 3: for each j from 1 ton n,add j to fn,if j divides fn
# step 4: Use cf for list of common factors.
# step 5: for each f in fm,add f to cf if f also appears in fn.
# step 6: Return the largest (rightmost) value in cf.

def gcd(m,n):
  fm = []
  for i in range(1,m+1):
    if m%i == 0:
      fm.append(i) 
  
  fn = []
  for j in range(1,n+1):
    if n%j == 0:
      fn.append(j)
  
  cf = []
  for i in fm:
      if i in fn:
        cf.append(i)
  
  print(cf[-1])
  
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    gcd(m,n)
    
# Method 2 (Single Scan)

# step 1: use fm,fn for list of factors m,n respectively
# step 2: for each i from 1 to max of m and n if i divides m add i to fm and add i to fn if i divides n.
#  (This way we can complete in a single scan)
# step 3: use cf for list of common factors.
# step 4: for each   f in fm,add f to cf if f also appears in fn.
# step 5: Return the largest (rightmost) value in cf.
  
  
def gcd(m,n):
    cf = []
    fm = []
    fn =[]
    for i in range(1,max(m,n)+1):
        if m % i == 0:
            fm.append(i)
        if n % i == 0:
            fn.append(i)
    for i in fm:
        if i in fn:
            cf.append(i)
    return(cf[-1])
  
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    print(gcd(m,n))
    
#Method 3

# (Reducinf the use of lists and run the scan from 1 to min(m,n) because m+1 will never be a factor of m so why use max instaed we go with min)
def gcd(m,n):
    cf = []
    for i in range(1,min(m,n)+1):
        if m % i == 0 and n %i == 0:
           cf.append(i)
    return(cf[-1])
  
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    print(gcd(m,n))


# Method 4
#  Instead of remembering each of the factors just get the max.
  def gcd(m,n):
    for i in range(1,min(m,n)+1):
        if m % i == 0 and n %i == 0:
           cfgr=i
    return(cfgr)
  
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    print(gcd(m,n))

#Method 5
# If we want to find gcd why to scan from beginning to end.Let's scan from backwards

def gcd(m,n):
    i = min(m,n)
    while i > 0:
        if m % i == 0 and n % i == 0:
            return(i)
        else:
            i=i-1
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    print(gcd(m,n))

    
#Euclid's algorithm  (Recursion)
def gcd(m,n):
     if m<n:      #assume m>=n
        (m,n)=(n,m)
     if m%n == 0:
         return(n)         
     else:
        diff = m-n
        return(gcd(max(n,diff),min(n,diff)))
 
if __name__ == '__main__':
    m = int(input())
    n = int(input())
    print(gcd(m,n))
    


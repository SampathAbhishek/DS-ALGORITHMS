#kadane's algorithm to solve max sub array
arr = [-2,1,-3,4,-1,2,1,-5,4]
sum = 0
maxi = arr[0]
for i in range(len(arr)):
    #step 1
        sum = sum + arr[i]   
    #step 2
        maxi = max(maxi,sum)
    #step 3
        if(sum<0):
           sum = 0

print(maxi)

#sample input ->[-2,1,-3,4,-1,2,1,-5,4]
#sample output ->6

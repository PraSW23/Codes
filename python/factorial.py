x = int(input("Enter the number : "))
res = 1
print("1",end="")
for i in range(2,x+1):
    print(" * ",i,end="")
    res = res*i
print(" =",res)
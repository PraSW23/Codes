x = "Goodbye"

print(x)
#x[1] = 'e' gives error because string in python is immutable 
print(x)
print("x1 = ",x[0:7]) # print from index 0 to index n-1 (7-1 = 6) (x[6] is e) 
print("x2 = ", x[2:5])
print("x3 = ", x[3])
print("x4 = ", x[0:])
print("x5 = ", x[:7])
print("x6 = ", x[:])
print("x7 = ", x[-7:-1]+x[-1])
print("x7.1 = ", x[-7:])
print("x8 = ", x[-3:-1])
print("x9 = ", x[-1], x[-2], x[-3], x[-4],x[-5],x[-6],x[-7], sep="")

print("x10 =",x[::2]) # with skip value i.e character in string is printed at index multiple of 2 

print("length of x is",len(x))
print("No of o in x is",x.count('o'))
print("oo is at index",x.find('oo'))

y= "   hell0  "
print(y , y.strip(),sep="\n")
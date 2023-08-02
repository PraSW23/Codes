x = ["hello", "how", "are", "you", "bye" , "good"]

for i in x:
    pass
print("loops")

i =0 
print("\nwhile")
while (i<len(x)):
    print(x[i],end=" ")
    i+=1

print("\n\nfor in")
for i in x:
    print(i,end=" ")
    

print("\n\nfor range")
for i in range(0,len(x),1): #step size 1
    print(x[i],end=",\n")

for i in range(0,len(x),2): #step size 2
    print(x[i],end=",,\n")

for i in range(0,len(x),3): #step size 3
    print(x[i],end=",,,\n")
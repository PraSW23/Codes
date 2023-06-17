
x  = input("Enter string : ")

for i in range(0,len(x)):
    if(i+1<=len(x)-1):
        if(x[i]==x[i+1]==' '):
            print("found at index ",i)
            break
    else:
        print("Not found")


y = x.find("  ")
if(y>-1):
    print("Found at",y)
    print(x.replace("  "," "))
else:
    print("NOT")
f = open("sample2.txt","w")
f.write(input("Write into file : "))
f.close()

f = open("sample2.txt","a")
f.write(input("Write into file : "))
f.close()

with open("sample2.txt","r") as f: #automatically close
    a = f.read()
    print(a)
    
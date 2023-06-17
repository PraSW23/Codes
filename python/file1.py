f = open("sample.txt","r")

x = f.read()
print(x)
f.close()

f = open("sample.txt","r")
x= f.readline()
print(x.strip())
f.close()

f = open("sample.txt","r")
x= f.readlines()
print(x)
f.close()
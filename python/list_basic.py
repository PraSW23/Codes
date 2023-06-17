x = [1, 2, "hello", 0.6, True]

print(x)
print(x[2],x[4])
x[1] = 8.8
print(x)
print("x0 = ",int(x[4]))

print("x1 = ",x[0:5])
print("x1.1 = ", x[2:4])
print("x2 = ", x[:])
print("x3 = ", x[-5:])
print("x4 = ", x[-3:-1])


y = [6,2,5,8,1,4,5]
y.sort()
print(y)
y.append(92)
print(y)
y.insert(0,999)
print(y)
y.pop(0)
print(y)
y.remove(92)
print(y)
print(y.count(5))
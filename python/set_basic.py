x = {3,1,5,2,3}
print(x)
# set is non-repeatitive and sorted
y = {}
print(type(y))

z = set()
y = set(y)
print(type(z),type(y))

y.add(0)
y.add(8)
y.add(8)
y.add(True)
y.add(7)
y.add((1,3,4))
y.add("name")

# y.add({1:3})
# y.add([1,2,4]) both line 17 and 18 throws error because both are unhashable
# or mutable or changable so we cannot generate hash from that

print(y, type(y),len(y))
print(y.pop(),y)


a = {1,3,6,7}
b = {2,8,1,7}
print("\nunion = ",a.union(a,b),"intersection = ",b.intersection(a,b))
print(a,b)
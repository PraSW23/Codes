class Vector:

    def __init__(self,vec):
        self.vec = vec

    def __str__(self):
        str = ""
        index = 0
        for key in self.vec:
            str += f"{key}a{index} + "
            index+=1
        return str[:-2]
    
    def __add__(self,num):
        li = []
        for i in range(len(self.vec)):
             li.append(self.vec[i] + num.vec[i])
        return Vector(li)
    
    def __mul__(self,num):
        sum = 0
        for i in range(len(self.vec)):
            sum+= self.vec[i] * num.vec[i]
        return sum



v1 = Vector([1,2,3,4,5])
v2 = Vector([1,2,3,4,6])
print(v1+v2)
print(v1*v2)


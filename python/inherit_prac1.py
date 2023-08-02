class C2d_vector:
    def __init__(self,i,j):
        self.i = i
        self.j = j

    def __str__(self):
        return f"{self.i}i + {self.j}j"

class C3d_vector(C2d_vector):
    def __init__(self,i,j,k):
        super().__init__(i,j)
        self.k = k

    def __str__(self):
        return f"{self.i}i + {self.j}j + {self.k}k"
    

v2d = C2d_vector(2,5)
v3d = C3d_vector(4,2,8)

print(v2d)
print(v3d)
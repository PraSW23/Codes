class Complex:
    
    def __init__(self,real,img):
        self.real = real
        self.img = img

    def __add__(self,num2):
       return Complex(self.real + num2.real , self.img + num2.img)
    
    def __mul__(self,num2):
        return Complex(((self.real*num2.real)-(self.img*num2.img)),(self.real*num2.img + self.img*num2.real))
    
    def __str__(self):
        return f"{self.real} + {self.img}i"
    

c1 = Complex(2,3)
c2 = Complex(5,7)

print(c1+c2)
print(c1*c2)

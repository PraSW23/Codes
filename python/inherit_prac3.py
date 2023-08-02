class Complex:
    
    def __init__(self,real,img):
        self.real = real
        self.img = img

    def __add__(self,num2):
       return self.real + num2.real , self.img + num2.img
    
    def __mul__(self,num2):
        return ((self.real*num2.real)-(self.img*num2.img)),(self.real*num2.img + self.img*num2.real) 
    
    

c1 = Complex(2,3)
c2 = Complex(5,7)

cr,ci = c1+c2
print(f"{cr} + {ci}i")

cr,ci = c1*c2
print(f"{cr} + {ci}i")
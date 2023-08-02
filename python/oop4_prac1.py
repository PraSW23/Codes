import math

class Calculator:
    def square(self):
        print(f"Square of {self.num} is {self.num * self.num}")

    def cube(self):
        print(f"Square of {self.num} is {math.pow(self.num,3)}")


    def sq_root(self):
        print(f"Square of {self.num} is {math.sqrt(self.num)}")
        #print(f"Square of {self.num} is {self.num**0.5}")



number = Calculator()
number.num = int(input("Enter number : "))
number.square()
number.cube()
number.sq_root()
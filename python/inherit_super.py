# super will run in same way for construtor super().__init__() for parent class constructor

class Person:
    country = "India"

    def takeBreath(self):
        print("I am Breathing")

    def hello(self):
        self.takeBreath()

    def show(self):
        print("i am in person")


class Employee(Person):
    company = "Honda"

    def getSalary(self):
        print("Salary is 100000")

    def takeBreath(self):
        super().takeBreath()
        print("Happily Breathing")

    def show(self):
        print("i am in employ")
        super().show()       # calling show of parent



class Programmer(Employee):  # nearest(Employee) parent has more priority
    company = "Fiverr"

    def getSalary(self):
        print("NO salary")
    
    def show(self):
        print("i am in programmer")
        #self.show()
        super().show()  # calling show of parent

p = Person()
e = Employee()
pr = Programmer()

"""
p.hello()
e.takeBreath()
pr.takeBreath() # nearest parent has more priority
"""
pr.show()

class Person:
    country = "India"

    def takeBreath(self):
        print("I am Breathing")

class Employee(Person):
    company = "Honda"

    def getSalary(self):
        print("Salary is 100000")

    def takeBreath(self):
        print("Happily Breathing")


class Programmer(Employee):  # nearest(Employee) parent has more priority
    company = "Fiverr"

    def getSalary(self):
        print("NO salary")


p = Person()
e = Employee()
pr = Programmer()

p.takeBreath()
e.takeBreath()
pr.takeBreath() # nearest parent has more priority

print(pr.company)
print(e.company)
print(pr.country)

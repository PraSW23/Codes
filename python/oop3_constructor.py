class Employee:
    company = "google"

    def __init__(self):  #this function automatically calls itself at the creation of instance
        print("hello")

ankit = Employee()


class Employee2:
    company = "google"

    def __init__(self,name,salary):
        self.salary,self.name = salary,name
        print("Printed automatically without being called due to constructor")

    def getDetails(self):
        print(f"Name of Employ is {self.name} and salary is {self.salary}")



amit = Employee2("amit",5000)

amit.getDetails()

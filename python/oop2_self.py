class Employee:
    company = "Google"

    def greet():
        print("Hello ")

    def getSalary(self):
        print(f"Salary is {self.salary} and company is {self.company}")

    @staticmethod     #decorator
    def bye():
        print("Thank You! ")


amit = Employee()

Employee.greet()

# amit.greet()  throws error as Employee.getSalary() takes 0 positional arguments but 1 was given
amit.salary = "30k"
Employee.getSalary(amit)
amit.getSalary()

amit.bye() # does not throw error because of @staticmethod so it does not convert it into Employee.bye(amit)





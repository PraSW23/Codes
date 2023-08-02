class Employ:
    company = "Facebook"
    salary = 100
    location = "Delhi"

    def change_salary(self,sal):  #only change the salary of instance or object not class
        self.salary = sal

    def change_Salary(self,sal):
        self.__class__.salary = sal  #dendur class

    @classmethod                     #decorator
    def Ch_Salary(cls,sal):
        cls.salary = sal

e = Employ()
print(e.salary)
print(Employ.salary)

print("\n")
e.change_salary(500)
print(e.salary)
print(Employ.salary)

print("\n")
e.change_Salary(700)
print(e.salary)
print(Employ.salary)

print("\n")
e.Ch_Salary(900)
print(e.salary)
print(Employ.salary)
class Employee:
    company = "Google"

    def showDetails(self):
        print("This is an Employ")

class Programmer(Employee):
    #company = "Youtube"

    def showDetails(self):
        print("This is a Programmer")


e = Employee()
e.showDetails()
p = Programmer()
p.showDetails()
print(p.company)
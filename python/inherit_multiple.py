class Emlploy:
    id = 4
    company = "Google"

    def show(self):
        print("In employ")

    def income(self):
        print("income is 10000")

class Freelancer:
    level = 0
    company = "Fiverr"

    def show(self):
        print("In Fiverr")

    def income(self):
        print("income is 10000")

class Programmer(Freelancer,Emlploy): # first parameter class gets prioty(high,low,very low)

    def show(self):
        print("in Programmer")


p = Programmer()

print(p.company) # freelancer has more priority
print(p.id)
print(p.level)
p.show()
p.income() # freelancer has more priority
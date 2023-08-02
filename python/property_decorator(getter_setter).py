class Employ:
    company = "TCS"
    salary = 5000
    salary_bonus = 500
    #Total_sal = 6500

    @property          # getter
    def total_sal(self):
        return self.salary + self.salary_bonus
    
    @total_sal.setter   # setter
    def total_sal(self,val):
        self.salary_bonus = val - self.salary 


e = Employ()
print(e.total_sal)

e.total_sal = 5200
print(e.salary_bonus)
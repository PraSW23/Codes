class Employee:
    salary = 5000
    increament = 500
    
    @property
    def salary_after_incr(self):
        return self.salary + self.increament
    
    @salary_after_incr.setter
    def salary_after_incr(self,sal):
        self.increament = self.salary_after_incr - sal


e = Employee()
print(e.salary_after_incr)
print(e.increament)
e.salary_after_incr = 3000
print(e.increament)

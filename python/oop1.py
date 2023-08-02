class Employee:             
    company = "google"          # class attributes

amit = Employee()               # creating instance of class
ajay = Employee()

"""
if we use amit  = Employee instead of amit = Employee()

the instances amit and ajay are assigned the class itself (Employee) rather than creating instances of the class. 
As a result, amit and ajay become references to the Employee class itself,
not instances of the class. Therefore, when you access attributes like amit.company or ajay.company, 
you are referring to the class attribute company directly.


if we use amit = Employee()
correctly creates instances of the Employee class using parentheses () when assigning to amit and ajay.
 This ensures that amit and ajay are separate instances of the Employee class.
 Consequently, you can access and modify instance attributes such as salary,
 and modifying the company attribute on amit creates a new instance attribute specific to that instance.

"""

print(Employee.company)
ankit = Employee
ankit.company = "Facebook"
print(Employee.company)


print("amit and ajay company \n" + amit.company)
print(ajay.company)

Employee.company = "Amazon"      # changing class attribute

print(amit.company)
print(ajay.company)


amit.salary = 3000    # instance attribute (has more priority than class attribute)
ajay.salary = 4000

print(amit.salary)
print(ajay.salary)

amit.company = "Microsoft"

print(amit.company)
print(ajay.company)


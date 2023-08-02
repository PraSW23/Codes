class namee:

    def __init__(bye): # it(bye) can be any variable but it should be self
        bye.name = input("Enter Name : ")
        bye.country = input("Country : ")
        bye.age = input("Enter Age : ")

    def getDetails(bye):
        print(f"\nName -> {bye.name}\nCountry -> {bye.country}\nEnter Age -> {bye.age}")

student = namee()
student.getDetails()
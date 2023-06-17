myDict = {
    "Pankha" : "Fan",
    "Khilona" : "Toy",
    "Ghar" : "House",
    "Rona" : "Crying"
}

y  = input("Enter the word to find meaning ")
print(myDict.get(y))


myDict1 = {}

x = input("Enter name : ")
y = input("Enter fav language :")
z = {
    x:y
}
myDict1.update(z)
print(myDict1)
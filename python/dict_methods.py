myDict = {
    "name": "Rakesh",
    "rollno.":1234,
    "Nationality" : "Indian",
    "address": { "City ":"Pune", "State":"Maharastra"},
    "marks":[23,35, 32, 25],
    1.5:"exit",
    True:"yes"

}
print(myDict,end="\n\n")
print(myDict.keys())
print(list(myDict.values()),end='\n\n')
print("list items =",myDict.items())

updateDict = {
    "mobno.": 1234456,
    "married":False,
    "rollno.":9999
}
myDict.update(updateDict)
print("\nupdated = ",myDict)

print(myDict.get("rollno."))
print(myDict.get("roll no.")) #retuns none if key is not present in dictionary
#print(myDict["roll no."]) throws error if key is not present in dictionary


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
print(myDict["rollno."],myDict["name"],myDict[1.5],myDict[True],sep=",",end="\n\n")

myDict["name"] = "Kapil"
print(myDict)
print("\nname : ",myDict["name"])
print("state : ",myDict["address"]["State"])
with open("sample2.txt","r") as f:
    a = f.read()
    x = a.find("twinkle")
    if(x>-1):
        print("found at index : ",x)
    else:
        print("Not found")
    
with open("sample2.txt","r") as f:
    a = f.read()
    x = a.replace("twinkle","######")
    
with open("sample2.txt","w") as f:
    a = f.write(x + "end.")
    
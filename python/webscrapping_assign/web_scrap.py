import requests

def write_into_file(url,path):
    r = requests.get(url)
    #print(type(r))
    with open(path,"w") as f:
        f.write(r.text)


url = "https://www.rivan.in"

write_into_file(url,"new.html")

#print(text)

#with open text.txt
import requests
from bs4 import BeautifulSoup
import pandas as pd

url = "https://www.rivan.in"

r = requests.get(url)

#print(r.text)

data = {"Tags":[],"Attributes":[],"Class":[],"ID":[],"Content":[]}

soup = BeautifulSoup(r.text,'html.parser')

#print(len(soup.find_all()))
#print(len(soup.children))


for tag in soup.find_all():
    #print(list(tag.attrs.keys()))
    #print(tag.string)
    data["Attributes"].append(list(tag.attrs.keys()))
    data["Tags"].append(tag.name)
    data["Class"].append(tag.get("class"))
    data["ID"].append(tag.get("id"))
    #print(tag.children)
    #print("len = ",len(tag.children))
    if(len(tag.find_all())==0):
        data["Content"].append(tag.string)
    else:
        data["Content"].append("")
        

df = pd.DataFrame.from_dict(data)
df.to_excel("data.xlsx",index=False)
df.to_csv("data.csv",index=False)
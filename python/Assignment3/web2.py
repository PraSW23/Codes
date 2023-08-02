import requests
from bs4 import BeautifulSoup
import pandas as pd

url = "https://www.rivan.in"
r = requests.get(url)

data = {"Sections": [], "Description": [], "Details": []}

soup = BeautifulSoup(r.text, 'html.parser')

def listToString(s):
    str1 = ""
    for ele in s:
        if ele:
            str1 += ele + ','
    return str1

card_titles = soup.find_all(class_="card-title")
s = []

for key in card_titles:
    s.append(key.string)

str_data = listToString(s)
print(str_data)

def other():
    data["Description"].append = "bye"


for tag in soup.find_all(class_="nav-item"):
    print(tag.string)
    data["Sections"].append(tag.string)
    if tag.string == "About":
        other()
    else:
        data["Description"].append("Description_placeholder")  # Replace "Description_placeholder" with actual description
    data["Details"].append("Details_placeholder")  # Replace "Details_placeholder" with actual details

df = pd.DataFrame.from_dict(data)
df.to_excel("data1.xlsx", index=False)
df.to_csv("data1.csv", index=False)

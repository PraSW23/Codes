import requests
from bs4 import BeautifulSoup
import pandas as pd
import textwrap

url = "https://www.rivan.in"
r = requests.get(url)

data = {"Tags": [], "Attributes": [], "Class": [], "ID": [], "Content": []}

soup = BeautifulSoup(r.text, 'html.parser')

def listToString(s):
    return ','.join(s)

for tag in soup.find_all():
    data["Attributes"].append(listToString(list(tag.attrs.keys())))
    data["Tags"].append(tag.name)
    if tag.get("class") is None:
        data["Class"].append(" - ")
    else:
        data["Class"].append(listToString(list(tag.get("class"))))
    if tag.get("id") is None:
        data["ID"].append(" - ")
    else:
        data["ID"].append(tag.get("id"))
 
    if len(tag.find_all()) == 0:
        if tag.string is None:
            data["Content"].append(" - ")
        else:
            if tag.name == "script":
                data["Content"].append("Hidden")
            else:
                # Wrap content to fit within the cell width
                wrapped_text = textwrap.fill(tag.string.strip(), width=30)
                data["Content"].append(wrapped_text)
    else:
        data["Content"].append(" - ")

df = pd.DataFrame.from_dict(data)
df.to_csv("data.csv", index=False)


writer = pd.ExcelWriter("data.xlsx", engine="xlsxwriter")
df.to_excel(writer, index=False)

# Get the xlsxwriter workbook and worksheet objects
workbook = writer.book
worksheet = writer.sheets["Sheet1"]

# Adjust row heights to fit the content
for i, row in enumerate(df.iterrows()):
    row_height = 18  # Default row height
    for col in df.columns:
        cell_data = str(row[1][col])
        cell_len = len(cell_data)
        cell_lines = cell_data.count('\n') + 1
        cell_height = (cell_lines * 14) + 8  # Adjust height based on lines and padding
        if cell_height > row_height:
            row_height = cell_height
    worksheet.set_row(i + 1, row_height)  # Add 1 to skip the header row

writer._save()

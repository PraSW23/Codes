from bs4 import BeautifulSoup

with open("new.html","r") as f:
    html_doc = f.read()

link = "https://youtu.be/4tAp9Lu0eDI"

soup = BeautifulSoup(html_doc,'html.parser')

print(soup.title.string)
print(soup.find_all('a')[1])
sum = ""
for link in soup.find_all('a') :
    print(link.get("href"))
    sum += link.get_text() + "\n"

print(sum)

print(soup.p["class"])

print(len(soup.select("div.plan-body")))
print(soup.div.get("class"))
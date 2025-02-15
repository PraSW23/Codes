import os
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import pandas as pd

def scrape_website_with_selenium(url):
    
    chrome_driver_path = '/home/prakhar/Downloads/chromedri/chromedriver'
    os.environ['PATH'] += ":" + chrome_driver_path
    html_content = ""
    
    driver = webdriver.Chrome()

    try:
        # Navigating to the URL
        driver.get(url)

        
        for _ in range(300):
            
            driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
            time.sleep(2) 

       
        html_content = driver.page_source

    except Exception as e:
        print("Error:", e)

    finally:
        
        driver.quit()

        with open("new.html", "w") as f:
            f.write(html_content)
    return html_content

def split1(input_string):
    return input_string.split(',')  

if __name__ == "__main__":
    url_to_scrape = "https://intake.steerhealth.io/doctor-search/aa1f8845b2eb62a957004eb491bb8ba70a"  
    content = scrape_website_with_selenium(url_to_scrape)

    
    soup = BeautifulSoup(content, "html.parser")

    data = []
    for key in soup.find_all(class_="ProviderCard__Wrapper-sc-161r76h-0 jWWAef"):
        name = key.find(class_="inner").get_text()
        expertise = key.find(class_="center").get_text()
        expertise_parts = split1(expertise)
        department = expertise_parts[0].strip() if len(expertise_parts) > 0 else ''
        position = expertise_parts[1].strip() if len(expertise_parts) > 1 else ''
        phone = key.find_all(class_="center")[1].get_text().strip()
        address = key.find_all(class_="center")[2].get_text().strip()

        data.append([name, expertise, department, position, phone, address])

    df = pd.DataFrame(data, columns=["Name", "Expertise", "Department", "Position", "Phone No", "Address"])
    df.to_excel("data.xlsx", index=False)


import os
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
import pandas as pd

dic = {"Name": [], "Expertise": [], "Department": [], "Position": [], "Phone No": [], "Address": []}

def scrape_website_with_selenium(url):
    chrome_driver_path = '/home/prakhar/Downloads/chromedriver'
    os.environ['PATH'] += ":" + chrome_driver_path
    html_content = ""
    
    
    driver = webdriver.Chrome()

    try:
        driver.get(url)

        
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "inner"))
        )

       
        scroll_height = 0
        max_scroll_iterations = 100  
        scroll_interval = 5  
        prev_scroll_height = 0
        before_five = 0
        consecutive_failed_scrolls = 0
        scroll_wait_time = 2  

        for _ in range(max_scroll_iterations):
            scroll_height += 1000
            driver.execute_script(f"window.scrollTo(0, {scroll_height});")
            print(f"Scrolling to {scroll_height} pixels...")  
            time.sleep(scroll_wait_time)

            
            current_scroll_height = driver.execute_script("return Math.max( document.body.scrollHeight, document.body.offsetHeight, document.documentElement.clientHeight, document.documentElement.scrollHeight, document.documentElement.offsetHeight );")

            
            if current_scroll_height <= prev_scroll_height and current_scroll_height <= before_five:
                consecutive_failed_scrolls += 1
                if consecutive_failed_scrolls >= 5:
                    print("Reached the bottom of the page or content not loading properly. Exiting...")
                    break
            else:
                prev_scroll_height = current_scroll_height
                consecutive_failed_scrolls = 0

           
            if _ % scroll_interval == 0:
                before_five = current_scroll_height

        
        html_content = driver.page_source

    except Exception as e:
        print("Error:", e)

    finally:
        
        driver.quit()

    return html_content


def split1(input_string):
    return input_string.split(',')

if __name__ == "__main__":
    url_to_scrape = "https://intake.steerhealth.io/doctor-search/aa1f8845b2eb62a957004eb491bb8ba70a"  
    content = scrape_website_with_selenium(url_to_scrape)

   
    soup = BeautifulSoup(content, "html.parser")

    for key in soup.find_all(class_="ProviderCard__Wrapper-sc-161r76h-0 jWWAef"):
        dic["Name"].append(key.find(class_="inner").get_text())
        dic["Expertise"].append(key.find(class_="center").get_text())
        expertise_parts = split1(key.find(class_="center").get_text())
        dic["Department"].append(expertise_parts[0] if len(expertise_parts) > 0 else ' - ')
        dic["Position"].append(expertise_parts[1] if len(expertise_parts) > 1 else ' - ')
        dic["Phone No"].append(key.find_all(class_="center")[1].get_text())
        dic["Address"].append(key.find_all(class_="center")[2].get_text())

    df = pd.DataFrame.from_dict(dic)
    df.to_csv("data.csv")
    df.to_excel("data.xlsx")

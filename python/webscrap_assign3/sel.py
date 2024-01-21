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
    
    # Creating the webdriver.Chrome object
    driver = webdriver.Chrome()

    try:
        driver.get(url)

        # Wait for the "inner" element to be present on the page before scrolling
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "inner"))
        )

        # Scroll to the end of the page by incrementally increasing the scroll height
        scroll_height = 0
        max_scroll_iterations = 100  # Adjust this value based on your requirements
        scroll_interval = 5  # Break out after every 5 scrolls to check for proper loading
        prev_scroll_height = 0
        before_five = 0
        consecutive_failed_scrolls = 0
        scroll_wait_time = 2  # Increase this value for slower internet connections

        for _ in range(max_scroll_iterations):
            scroll_height += 1000
            driver.execute_script(f"window.scrollTo(0, {scroll_height});")
            print(f"Scrolling to {scroll_height} pixels...")  # For troubleshooting
            time.sleep(scroll_wait_time)

            # Check if the page has reached the bottom by comparing the current scroll height
            # with the maximum scroll height
            current_scroll_height = driver.execute_script("return Math.max( document.body.scrollHeight, document.body.offsetHeight, document.documentElement.clientHeight, document.documentElement.scrollHeight, document.documentElement.offsetHeight );")

            # Break out if the current scroll height is less than or equal to the previous and before_five scroll heights
            if current_scroll_height <= prev_scroll_height and current_scroll_height <= before_five:
                consecutive_failed_scrolls += 1
                if consecutive_failed_scrolls >= 5:
                    print("Reached the bottom of the page or content not loading properly. Exiting...")
                    break
            else:
                prev_scroll_height = current_scroll_height
                consecutive_failed_scrolls = 0

            # Update the before_five variable after every five scrolls
            if _ % scroll_interval == 0:
                before_five = current_scroll_height

        # Getting the page source after scrolling and waiting for dynamic content to load
        html_content = driver.page_source

    except Exception as e:
        print("Error:", e)

    finally:
        # Closing the webdriver after scraping
        driver.quit()

    return html_content


def split1(input_string):
    return input_string.split(',')

if __name__ == "__main__":
    url_to_scrape = "https://intake.steerhealth.io/doctor-search/aa1f8845b2eb62a957004eb491bb8ba70a"  # Replace with the URL you want to scrape
    content = scrape_website_with_selenium(url_to_scrape)

    # Create the BeautifulSoup object to parse the HTML content
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

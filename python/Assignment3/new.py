import os
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import pandas as pd

def scrape_website_with_selenium(url):
    # Set the path to the ChromeDriver executable as an environment variable
    chrome_driver_path = '/home/prakhar/Downloads/chromedri/chromedriver'
    os.environ['PATH'] += ":" + chrome_driver_path
    html_content = ""
    # Create the webdriver.Chrome object
    driver = webdriver.Chrome()

    try:
        # Navigate to the URL
        driver.get(url)

        # Replace the number with the desired number of scrolls or use a loop to scroll until you get all the data
        for _ in range(300):
            # Scroll to the bottom of the page to load more data
            driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
            time.sleep(2)  # Wait for the content to load (adjust the wait time as needed)

        # Get the page source after scrolling and waiting for dynamic content to load
        html_content = driver.page_source

    except Exception as e:
        print("Error:", e)

    finally:
        # Close the webdriver after scraping
        driver.quit()

        with open("new.html", "w") as f:
            f.write(html_content)
    return html_content

def split1(input_string):
    return input_string.split(',')  # Split using comma as separator

if __name__ == "__main__":
    url_to_scrape = "https://intake.steerhealth.io/doctor-search/aa1f8845b2eb62a957004eb491bb8ba70a"  # Replace with the URL you want to scrape
    content = scrape_website_with_selenium(url_to_scrape)

    # Create the BeautifulSoup object to parse the HTML content
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


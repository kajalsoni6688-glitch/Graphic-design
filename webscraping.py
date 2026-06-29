import requests
from bs4 import BeautifulSoup
import pandas as pd
# Website URL
url = "https://books.toscrape.com/"

# Send GET request
response = requests.get(url)

# Check if request was successful
if response.status_code == 200:

    soup = BeautifulSoup(response.text, "html.parser")

    products = soup.find_all("article", class_="product_pod")

    data = []

    for product in products:
        # Product Name
        name = product.h3.a["title"]

        # Price
        price = product.find("p", class_="price_color").text

        # Rating
        rating = product.find("p", class_="star-rating")["class"][1]

        data.append({
            "Product Name": name,
            "Price": price,
            "Rating": rating
        })

    # Save to CSV
    df = pd.DataFrame(data)
    df.to_csv("products.csv", index=False)

    print("Data scraped successfully!")
    print(df)

else:
    print("Failed to retrieve webpage.")
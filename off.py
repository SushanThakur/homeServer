import requests

# Define the URL
url = 'http://192.168.1.74/x=0'

# Make a GET request
try:
    response = requests.get(url)

    # Check if the request was successful
    if response.status_code == 200:
        print(f"Request successful: {response.text}")
    else:
        print(
            f"Failed to make the request. Status code: {response.status_code}")
except requests.exceptions.RequestException as e:
    print(f"An error occurred: {e}")

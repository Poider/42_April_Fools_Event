import requests

base_url = "https://pokeapi.co/api/v2/"
endpoint = "pokemon/"

print("Enter the name of a Pokemon:"),
name = raw_input()
# sending a request to the api then getting response and hadnling it
response = requests.get(base_url + endpoint + name)

if response.status_code == 200:
    # Extract the JSON data from the response
    data = response.json()
    
    pokename = data["name"]
    print("Name:"),
    print(pokename)
    
    abilities = data["abilities"]
    print("Abilities:")
    for index in abilities:
        ability = index["ability"]
        print("- " + ability["name"])
else:
    print("not found")

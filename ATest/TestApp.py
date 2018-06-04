import argparse
import json
import requests

post_message = {"cardType": ["Visa", "MasterCard", "EFTPOS"], "TransactionType": ["Cheque", "Savings", "Credit"]}
expected_response = {"terminalID":101,"transactions":[{"cardType":"Visa","TransactionType":"Credit"},{"cardType":"EFTPOS","TransactionType":"Savings"}]}

def test_create_terminal():
    response = requests.post('http://localhost/create_terminal', json=post_message)
    print(response.status_code)
    if response.status_code != 200:
        print("Failed to create a terminal status: " + str(response.status_code))

    response_json = response.json()
    if response_json['id'] is None:
        print("Failed to receive terminal Id from web server")
    else:
        print(response_json['id'])

def test_get_terminal():
    response = requests.get('http://localhost/get_terminal/1')
    print(response.status_code)
    if response.status_code != 200:
        print("Failed to get terminal status: " + str(response.status_code))
    response_json = response.json()
    if response_json['terminalID'] != 1:
        print("Failed to get terminal!")
    else:
        print("Terminal id - " + str(response_json['terminalID']))
        print("Response - " + str(response_json))
        print("Succeeded to get terminal details")

if __name__ == '__main__':
    print '...............Testing started..............'
    print '............Test create terminal............'
    #test_create_terminal()
    print '..............Test get terminal.............'
    test_get_terminal()
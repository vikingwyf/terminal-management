import argparse
import json
import requests

post_message = {"cardType": ["Visa", "MasterCard", "EFTPOS"], "TransactionType": ["Cheque", "Savings", "Credit"]}


def test_create_terminal():
    response = requests.post('https://jsonplaceholder.typicode.com/posts', json=post_message)
    print(response.status_code)
    if response.status_code != 201:
        print("Failed to create a terminal status: " + response.status_code)

    response_json = response.json()
    if response_json['id'] is None:
        print("Failed to receive terminal Id from web server")
    else:
        print(response_json['id'])

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Terminal management test app')
    parser.add_argument('port', type=int, help='Web Server port number')
    parser.add_argument('ip', help='Web Server IP')
    args = parser.parse_args()

    print '............Testing started............'
    test_create_terminal()
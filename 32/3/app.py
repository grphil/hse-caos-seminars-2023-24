#!python3

import logging
import json
import sys

from flask import Flask, request
from pymongo import MongoClient
import yaml

app = Flask(__name__)
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

with open(sys.argv[1], 'r') as file:
    options = yaml.safe_load(file)

def get_database():
    CONNECTION_STRING = options['mongo']
    client = MongoClient(CONNECTION_STRING)
    return client['docker-app']

db = get_database()
collection = db['app']

@app.route('/', methods=['GET', 'POST'])
def apply_model():
    if request.method == 'POST':
        if ('key' not in request.form) or ('value' not in request.form):
            return 'please provide valid arguments -- key and value\n', 400
        key, value = request.form['key'], request.form['value']
      
        collection.update_one(
            {'key': key},
            {"$set": {'value': value}},
            True,
        )

        return 'done', 200
    elif request.method == 'GET':
        key = request.args.get('key', None)
        if key is None:
            return 'please provide valid argument -- key\n', 400

        res = collection.find_one({'key': key})
        if res is None:
            return 'there is no such key-value\n', 400
        return f'{res['value']}', 200

app.run(debug=True, host=options['host'], port=options['port'])

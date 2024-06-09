#!python3
import logging
import json

from flask import Flask, request

app = Flask(__name__)
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

data = dict()

@app.route('/', methods=['GET', 'POST'])
def apply_model():
    if request.method == 'POST':
        if ('key' not in request.form) or ('value' not in request.form):
            return 'please provide valid arguments -- key and value\n', 400
        key, value = request.form['key'], request.form['value']
        data[key] = value
        return 'done', 200
    elif request.method == 'GET':
        key = request.args.get('key', None)
        if key is None:
            return 'please provide valid argument -- key\n', 400
        if key not in data.keys():
            return 'there is no such key-value\n', 400
        return f'{data[key]}', 200

app.run(host='0.0.0.0', port='8080')

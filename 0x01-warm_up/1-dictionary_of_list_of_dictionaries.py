#!/usr/bin/python3
"""
returns information about his/her TODO list progress for a
given employee ID using a REST API and export data in the JSON format
"""
from requests import get
import json
from collections import OrderedDict


def get_todo_all():
    """returns employee's TODO list progress"""
    r_user = get('https://jsonplaceholder.typicode.com/users')

    try:
        user_dict = r_user.json()
        data = OrderedDict()  # preserve order of dict values
        for user in user_dict:
            data['{}'.format(user["id"])] = []
            r_todo = get('https://jsonplaceholder.typicode.com/todos?'
                         'userId={}'.format(user["id"]))
            task_list = r_todo.json()

            for task in task_list:
                a_dict = OrderedDict()
                a_dict["username"] = user["username"]
                a_dict["task"] = task["title"]
                a_dict["completed"] = task["completed"]
                data['{}'.format(user["id"])].append(a_dict)
        with open("todo_all_employees.json", "w") as jsonfile:
            json.dump(data, jsonfile)
    except:
        pass

if __name__ == "__main__":
    get_todo_all()

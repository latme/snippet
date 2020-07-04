#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sqlite3
import env


class FisheepSqlite:
    def __init__(self, db_filename='sqlite.db'):
        self.sqlite_filename = os.path.join(env.USER_HOME_DIR, db_filename)
        self.conn = sqlite3.connect(self.sqlite_filename)
        self.cursor = self.conn.cursor()

    def __del__(self):
        self.conn.close()

    def del_db_file(self):
        if os.path.isfile(self.sqlite_filename):
            os.remove(self.sqlite_filename)

    def _execute(self, sql_str):
        try:
            self.cursor.execute(sql_str)
        except Exception as e:
            print(e)
            return False
        return True

    def create_demo_table(self):
        retval = self._execute('''CREATE TABLE demo
                                (id      INT PRIMARY KEY NOT NULL,
                                name     TEXT NOT NULL,
                                address  CHAR(50) NOT NULL,
                                salary   REAL);''')
        self.conn.commit()
        return retval

    def insert_demo(self):
        retval = self._execute('''INSERT INTO demo (id,name,address,salary)
                                VALUES (1, 'fisheep', 'fisheep.cc', 1.00);''')
        self.conn.commit()
        return retval

    def select_demo(self):
        result = self.cursor.execute('''SELECT id,name,address FROM demo;''')
        for row in result:
            print('id = ', row[0])
            print('name = ', row[1])
            print('salary = ', row[2])
        return result

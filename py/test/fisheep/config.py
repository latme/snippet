#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import os
import json
import configparser


USER_HOME_DIR = os.path.expanduser('~')
FISHEEP_USRCFG_DIR = os.path.join(USER_HOME_DIR, '.fisheep')
CFG_INI = {
    'section': {
        'key': 'value'
    },
    'config': {
        'name': 'ini'
    },
    'cmdline': {
        'cmd': 'ls',
        'opts': '-la'
    }
}
CFG_JSON = {
    'key': 'value',
    'key2': {
        'sub_key': 'sub_value'
    },
    'key3': {
        'sub_key': {
            'sub_sub_key': 'sub_sub_value'
        }
    },
    'name': 'json',
    'cmdline': {
        'cmd': 'ls',
        'opts': '-la'
    }
}


class FisheepConfig:
    def __init__(self):
        self.ini_cfg_filename  = os.path.join(FISHEEP_USRCFG_DIR, 'cfg.ini')
        self.json_cfg_filename = os.path.join(FISHEEP_USRCFG_DIR, 'cfg.json')
        self.ini_cfg = None
        self.json_cfg = None
        if not os.path.exists(FISHEEP_USRCFG_DIR):
            os.mkdir(FISHEEP_USRCFG_DIR)

    def load_ini_cfg(self):
        try:
            config = configparser.ConfigParser()
            config.read(self.ini_cfg_filename)
            self.ini_cfg = config._sections
        except Exception as e:
            print(e)
            return None
        return self.ini_cfg

    def load_json_cfg(self):
        try:
            fp_json = open(self.json_cfg_filename, 'r')
            self.json_cfg = json.load(fp_json)
            fp_json.close()
        except Exception as e:
            print(e)
            return None
        return self.json_cfg

    def store_ini_cfg(self):
        if os.access(self.ini_cfg_filename, os.F_OK):
            return
        fp_ini = open(self.ini_cfg_filename, 'w')
        config = configparser.ConfigParser()
        config.read_dict(CFG_INI)
        config.write(fp_ini)
        fp_ini.close()

    def store_json_cfg(self):
        if os.access(self.json_cfg_filename, os.F_OK):
            return
        fp_json = open(self.json_cfg_filename, 'w')
        json.dump(CFG_JSON, fp_json)
        fp_json.close()

    def clean_all_cfg(self):
        if os.path.isfile(self.json_cfg_filename):
            os.remove(self.json_cfg_filename)
        if os.path.isfile(self.ini_cfg_filename):
            os.remove(self.ini_cfg_filename)
        if os.path.isdir(FISHEEP_USRCFG_DIR):
            os.rmdir(FISHEEP_USRCFG_DIR)

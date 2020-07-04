#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import unittest
import fisheep.config as fsc


class MyTestCase(unittest.TestCase):
    def setUp(self) -> None:
        self.rc = fsc.FisheepConfig()
        self.rc.store_ini_cfg()
        self.rc.store_json_cfg()

    def tearDown(self) -> None:
        self.rc.clean_all_cfg()

    def test_read_ini(self):
        ini_cfg = self.rc.load_ini_cfg()
        print(ini_cfg, type(ini_cfg))
        self.assertIsNotNone(ini_cfg, 'ini config')

    def test_read_json(self):
        json_cfg = self.rc.load_json_cfg()
        print(json_cfg, type(json_cfg))
        self.assertTrue(isinstance(json_cfg, dict), 'json config')


if __name__ == '__main__':
    unittest.main()

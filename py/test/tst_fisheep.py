import unittest
import fisheep.db as fsdb


class TestCaseSqlite(unittest.TestCase):
    def setUp(self) -> None:
        self.sqlite = fsdb.FisheepSqlite()

    def tearDown(self) -> None:
        self.sqlite.del_db_file()

    def test_operate(self):
        self.assertTrue(self.sqlite.create_demo_table(), 'create table')
        self.assertTrue(self.sqlite.insert_demo(), 'insert record')
        self.assertTrue(self.sqlite.select_demo(), 'query record')
        self.sqlite.del_db_file()


if __name__ == '__main__':
    unittest.main()

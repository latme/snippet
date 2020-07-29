import unittest
import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
import latme


class LatmeBaseTestCase(unittest.TestCase):
    def test_conv_digit_cn_to_num(self):
        dict_test_data = {'一': 1, '十': 10, '一十': 10, '一十一': 11, '一千零一': 1001}
        for cn, ref_num in dict_test_data.items():
            num = latme.convDigitCnToNum(cn)
            # self.assertEqual(num, ref_num)


if __name__ == '__main__':
    unittest.main()

/*
 * @Author: 辜思学
 * @Description: Q1. 将日期转换为二进制表示
 * @Date: 2024-09-08 10:30:17
 */

#include <bits/stdc++.h>

using namespace std;

string convertDateToBinary(string date)
{
    string res;
    int day = (date[8] - '0') * 10 + (date[9] - '0');
    int month = (date[5] - '0') * 10 + (date[6] - '0');
    int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');

    res = toBinary(day);
    res = res + '-' + toBinary(month);
    res = res + '-' + toBinary(year);

    reverse(res.begin(), res.end());

    return res;
}

string toBinary(int num)
{
    string res;
    while (num != 0)
    {
        res += num % 2 == 0 ? '0' : '1';
        num /= 2;
    }
    return res;
}
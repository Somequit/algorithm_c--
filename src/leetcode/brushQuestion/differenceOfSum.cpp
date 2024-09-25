/*
 * @Author: 辜思学
 * @Description: 2535. 数组元素和与数字和的绝对差
 * @Date: 2024-09-26 01:04:58
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 元素和（所有元素之和）一定大于数位和（所有元素拆分为每一数位之和）
*/
int differenceOfSum(vector<int> &nums)
{
    int res = 0;
    for (auto num : nums)
    {
        res += num;
        for (auto c : to_string(num))
        {
            res -= c - '0';
        }
    }

    return abs(res);
}
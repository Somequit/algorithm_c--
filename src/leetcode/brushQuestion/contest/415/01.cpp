/*
 * @Author: 辜思学
 * @Description: Q1. 数字小镇中的捣蛋鬼
 * @Date: 2024-09-15 10:31:34
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int curNum = 0;
    vector<int> res;
    for (auto num : nums)
    {
        if (num == curNum)
        {
            curNum++;
        }
        else
        {
            res.push_back(num);
        }
    }
    return res;
}

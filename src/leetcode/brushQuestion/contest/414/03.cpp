/*
 * @Author: 辜思学
 * @Description: Q3. 到达数组末尾的最大得分
 * @Date: 2024-09-08 10:31:08
 */

#include <bits/stdc++.h>

using namespace std;

long long findMaximumScore(vector<int> &nums)
{
    long long res = 0L;

    int n = nums.size();
    int curMaxNum = nums[0];
    for (int i = 1; i < n; i++)
    {
        res += curMaxNum;
        if (nums[i] > curMaxNum)
        {
            curMaxNum = nums[i];
        }
    }

    return res;
}
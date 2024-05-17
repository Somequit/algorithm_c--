/*
 * @Author: 辜思学
 * @Description: 2644. 找出可整除性得分最大的整数
 * @Date: 2024-05-18 03:56:10
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * divisors 排序后暴力计算每个数有多少个能够整除 nums，整除个数变大就更新答案
 */
int maxDivScore(vector<int> &nums, vector<int> &divisors)
{
    sort(divisors.begin(), divisors.end());

    int res = 0;
    int divCount = -1;
    for (int divisor : divisors)
    {
        int divCountTmp = 0;
        for (int num : nums)
        {
            if (num % divisor == 0)
            {
                divCountTmp++;
            }
        }

        if (divCountTmp > divCount)
        {
            divCount = divCountTmp;
            res = divisor;
        }
    }

    return res;
}
/*
 * @Author: 辜思学
 * @Description: 3164. 优质数对的总数 II
 * @Date: 2024-10-11 07:48:35
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 将 nums2 放入 count[nums2[j]]++ 数组中，再将每个 nums1[i]%k 为 0 的每个 nums1[i]/k 元素，求出所有的因子 f 通过 count[f] 数组加入结果
 */
long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int count[(int)1e6 + 1];
    memset(count, 0, sizeof(count));

    for (auto num2 : nums2)
    {
        count[num2]++;
    }

    long long res = 0;
    for (auto num1 : nums1)
    {
        if (num1 % k == 0)
        {
            for (int i = 1; i * i <= num1 / k; i++)
            {
                if (num1 / k % i == 0)
                {
                    res += count[i];
                    if (i != num1 / k / i)
                    {
                        res += count[num1 / k / i];
                    }
                }
            }
        }
    }

    return res;
}
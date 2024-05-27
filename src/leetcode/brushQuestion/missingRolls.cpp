/*
 * @Author: 辜思学
 * @Description: 2028. 找出缺失的观测数据
 * @Date: 2024-05-27 23:30:34
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 求出 n 个元素之和：(n+m)*mean - sum(rolls) = surplus，如果 n <= surplus <= 6*n 则一定有结果，
 * 结果包含 surplus/n、可能也有 surplus/n+1
 */
vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    int m = rolls.size();

    int surplus = (n + m) * mean - reduce(rolls.begin(), rolls.end());

    if (n <= surplus && surplus <= n * 6)
    {
        vector<int> res(surplus % n, surplus / n + 1);
        res.insert(res.end(), n - surplus % n, surplus / n);
        // for (int i = 0; i < n; i++)
        // {
        //     if (i < surplus % n)
        //     {
        //         res.push_back(surplus / n + 1);
        //     }
        //     else
        //     {
        //         res.push_back(surplus / n);
        //     }
        // }
        return res;
    }
    else
    {
        return {};
    }
}
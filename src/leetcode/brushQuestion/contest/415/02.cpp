/*
 * @Author: 辜思学
 * @Description: Q2. 最高乘法得分
 * @Date: 2024-09-15 10:35:38
 */

#include <bits/stdc++.h>

using namespace std;

long long maxScore(vector<int> &a, vector<int> &b)
{
    long long inf = 100000000000LL;
    int len = b.size();

    long long dp[4][len];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dp[i][j] = -inf;
        }
    }

    for (int i = 0; i < len; i++)
    {
        dp[0][i] = 1LL * a[0] * b[i];
    }

    for (int i = 1; i < 4; i++)
    {
        long long curMaxDp = dp[i - 1][i - 1];
        for (int j = i; j < len; j++)
        {
            dp[i][j] = curMaxDp + 1LL * a[i] * b[j];
            curMaxDp = max(curMaxDp, dp[i - 1][j]);
            // cout << dp[i][j] << " " << maxDp[j] << endl;
        }

        // cout << endl;
    }

    long long res = -inf;
    for (int i = 3; i < len; i++)
    {
        res = max(res, dp[3][i]);
    }
    return res;
}
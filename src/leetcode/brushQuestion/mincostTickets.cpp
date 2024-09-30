/*
 * @Author: 辜思学
 * @Description: 983. 最低票价
 * @Date: 2024-10-01 00:24:42
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * dp[i] 代表到第 i 天最低花费，dp[0]=0，如果 第i天 不旅游 dp[i]=dp[i-1]，否则 dp[i]=min(dp[i-1]+costs[0], dp[i-7]+costs[1], dp[i-30]+costs[2])
 */
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int dp[366];
    dp[0] = 0;

    for (int i = 1, j = 0; i < 366; i++)
    {
        if (i == days[j])
        {
            j++;
            dp[i] = min(min(dp[i - 1] + costs[0], dp[(i - 7) < 0 ? 0 : (i - 7)] + costs[1]), dp[(i - 30) < 0 ? 0 : (i - 30)] + costs[2]);
            // 后面不需要买票了，直接退出
            if (j == days.size())
            {
                return dp[i];
            }
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[365];
}
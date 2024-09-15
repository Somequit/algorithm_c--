/*
 * @Author: 辜思学
 * @Description: Q3. 形成目标字符串需要的最少字符串数 I(最后几组超时，可改为字典树优化常数)
 * @Date: 2024-09-15 11:58:19
 */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
ull base = 31;

int minValidStrings(vector<string> &words, string target)
{
    int inf = 10000;
    unordered_set<ull> hashWordPreSet[5000];

    for (auto word : words)
    {
        ull ans = 0;
        int i = 0;

        for (auto s : word)
        {
            ans = ans * base + s;
            hashWordPreSet[i].emplace(ans);
            i++;
        }
    }

    int len = target.size();

    int dp[len + 1];
    for (int i = 0; i < len + 1; i++)
    {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < len; i++)
    {
        if (dp[i] == inf)
        {
            break;
        }

        ull ans = 0;
        for (int j = 0; i + j < len; j++)
        {
            ans = ans * base + target[i + j];
            if (dp[i + j + 1] > dp[i] + 1 && hashWordPreSet[j].count(ans) == 1)
            {
                dp[i + j + 1] = dp[i] + 1;
            }
        }
    }

    return dp[len] == inf ? -1 : dp[len];
}
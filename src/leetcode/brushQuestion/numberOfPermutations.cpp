/*
 * @Author: 辜思学
 * @Description: 3193. 统计逆序对的数目
 * @Date: 2024-10-17 11:24:53
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 动态规划：
 * 状态定义：dp[i][j] 代表 [0,i-1] 凑成 j 个逆序对的排列总数
 * 递推方程：dp[i][j] = sum(dp[i-1][j-k])，0<=k<=min(i,j)
 *     新加一个数（即 i+1）需循环 [0,i] 放在下一位、可看做前面是 [1,i]、[1]+[3,i]...[0,n-2]+[n]、[0,n-1] 结果均一致；即不需要知道每个位置填哪些数，仅需要知道最后一位填的是第几大即可
 * 最后需要满足 requirements 情况，需要在 i=end 时，仅保留 dp[end][cnt] 其余 dp[end][] 置为 0
 */
int numberOfPermutations(int n, vector<vector<int>> &requirements)
{
    int mod = 1e9 + 7;

    int maxCnt = 0;
    unordered_map<int, int> requirementMap;
    for (auto requirement : requirements)
    {
        // 注意 end 从 0 开始
        requirementMap.emplace(requirement[0], requirement[1]);
        maxCnt = max(maxCnt, requirement[1]);
    }
    if (requirementMap.count(0) && 0 != requirementMap[0])
    {
        return 0;
    }

    int dp[n][maxCnt + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < maxCnt + 1; j++)
        {
            if (requirementMap.count(i) && j != requirementMap[i])
            {
                continue;
            }

            for (int k = 0; k < min(i, j) + 1; k++)
            {
                dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= mod;
            }
        }
    }

    return dp[n - 1][requirementMap[n - 1]];
}
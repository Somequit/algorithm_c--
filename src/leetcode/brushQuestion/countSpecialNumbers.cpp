/*
 * @Author: 辜思学
 * @Description: 2376. 统计特殊整数
 * @Date: 2024-09-20 11:35:26
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * i: 前 i 位
 * mask：填了哪些数字
 * is_limit：是否限制小于等于原数
 * is_num: 是否填写数字（未填写可看做第一位或全前导零）
 */
int dfs(int i, int mask, bool is_limit, bool is_num, const int nLen, const string s, int (*memo)[1 << 10])
{
    if (i == nLen)
    {
        // 0否 1是
        return is_num;
    }

    // !is_limit && is_num 代表前 i 位不等于 s，且已经填写过数字，此时才需要记忆化
    if (!is_limit && is_num && memo[i][mask] != -1)
    {
        return memo[i][mask];
    }

    int res = 0;
    // 跳过当前位
    if (!is_num)
    {
        res = dfs(i + 1, mask, false, false, nLen, s, memo);
    }

    int up = is_limit ? s[i] - '0' : 9;
    // 不跳当前位，首位不能为 0，不能出现过
    for (int j = is_num ? 0 : 1; j < up + 1; j++)
    {
        if (((mask >> j) & 1) == 0)
        {
            res += dfs(i + 1, mask | (1 << j), j == up ? is_limit : false, true, nLen, s, memo);
        }
    }
    // // !is_limit && is_num 代表前 i 位不等于 s，且已经填写过数字，此时才需要记忆化
    if (!is_limit && is_num)
    {
        memo[i][mask] = res;
    }

    return res;
}

/**
 * 数位 DP 模板
 */
int countSpecialNumbers(int n)
{
    string s = to_string(n);
    int nLen = s.size();
    int memo[nLen][1 << 10];
    memset(memo, -1, sizeof(memo));

    return dfs(0, 0, true, false, nLen, s, memo);
}
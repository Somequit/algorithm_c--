/*
 * @Author: 辜思学
 * @Description: 2207. 字符串中最多数目的子序列
 * @Date: 2024-09-24 13:09:05
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 首先由于子序列仅与 p0、p1 出现的顺序相关，因此 p0 放在开头（增加 text 中 p1 的个数） 或 p1 放在结尾（增加 text 中 p0 的个数）答案最优，
 * 其次原本 text 中子序列的个数，仅需要逆序找到每个 p0 出现时 p1 的个数再相加即可
 * 注意 p0 可能等于 p1，因此可以先加上 p1 的个数在计数 p1
 */
long long maximumSubsequenceCount(string text, string pattern)
{
    long long res = 0;
    int p0Count = 0;
    int p1Count = 0;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        if (text[i] == pattern[0])
        {
            res += p1Count;
            p0Count++;
        }
        if (text[i] == pattern[1])
        {
            p1Count++;
        }
    }

    return res + max(p0Count, p1Count);
}
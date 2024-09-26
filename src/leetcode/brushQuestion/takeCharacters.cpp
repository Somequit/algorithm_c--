/*
 * @Author: 辜思学
 * @Description: 2516. 每种字符至少取 K 个
 * @Date: 2024-09-27 02:09:22
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 枚举左边取的个数 i，使用滑动窗口的方式找到右边最少取的个数 j，找到 min(i+j)
 */
bool isCharacters(int count[], int k)
{
    for (int i = 0; i < 3; i++)
    {
        if (count[i] < k)
        {
            return false;
        }
    }
    return true;
}
int takeCharacters(string s, int k)
{
    int len = s.size();

    int count[3] = {0};
    for (char c : s)
    {
        count[c - 'a']++;
    }
    if (!isCharacters(count, k))
    {
        return -1;
    }

    memset(count, 0, sizeof(count));
    int j = len - 1;
    for (; !isCharacters(count, k); j--)
    {
        count[s[j] - 'a']++;
    }
    j++;

    int res = len - j;
    for (int i = 0; i < res; i++)
    {
        count[s[i] - 'a']++;
        while (j < len && isCharacters(count, k))
        {
            count[s[j] - 'a']--;
            j++;
        }

        if (!isCharacters(count, k))
        {
            j--;
            count[s[j] - 'a']++;
        }

        res = min(res, i + (len - j) + 1);
    }

    return res;
}

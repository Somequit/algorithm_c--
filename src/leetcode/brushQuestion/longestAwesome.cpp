/*
 * @Author: 辜思学
 * @Description: 1542. 找出最长的超赞子字符串
 * @Date: 2024-05-20 10:56:52
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 前缀异或：将前 i 个字符按数字异或、状压到 numMask 中，如果 numMask 为 0 或 某一位是 1 则可以形成回文串，
 * 遍历 s 字符串，前 i 个字符形成 numMask 异或 （0 或 某一位是 1），在 map 中查询是否存在，存在将下标相减即回文长度，
 * 由于异或的性质可得：numMaskLeft ^ numMask = 回文串，最后将 numMask 更新加入(如不存在，因为要存储最小下标的 numMask) map 中
 */
int longestAwesome(string s)
{
    int len = s.size();
    if (len == 1)
    {
        return 1;
    }

    int res = 1;
    unordered_map<int, int> mapNumMask;
    // 初始化不存在的情况
    mapNumMask[0] = -1;

    int numMask = 0;
    for (int i = 0; i < len; i++)
    {
        numMask ^= (1 << (s[i] - '0'));

        for (int j = 0; j < 10; j++)
        {
            if (mapNumMask.find(numMask ^ (1 << j)) != mapNumMask.end())
            {
                res = max(res, i - mapNumMask[numMask ^ (1 << j)]);
            }
        }

        // 存在 numMask
        if (mapNumMask.find(numMask) != mapNumMask.end())
        {
            res = max(res, i - mapNumMask[numMask]);
        }
        else
        {
            mapNumMask[numMask] = i;
        }

        // cout << numMask << ":" << res << endl;
        // for (auto it = mapNumMask.begin(); it != mapNumMask.end(); ++it)
        // {
        //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        // }
    }

    return res;
}

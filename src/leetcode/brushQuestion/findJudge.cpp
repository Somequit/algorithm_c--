/*
 * @Author: 辜思学
 * @Description: 997. 找到小镇的法官
 * @Date: 2024-09-22 13:51:06
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 一次循环：特殊情况仅有一人就是法官，其次如果信任数量较少则达不到：每个人（除了小镇法官）都信任这位小镇法官
 * 对 a 与 b 计数，边计数边判断当前是否是法官、即信任它的为 n-1 人（因为 a!=b 且 每对 a、b 均不相同），同时之前没有出现过法官，最后判断该法官是否会信任他人
*/
int findJudge(int n, vector<vector<int>>& trust) {
    if (n == 1)
    {
        return 1;
    }
    if (n > trust.size() + 1)
    {
        return  -1;
    }

    int res = -1;

    int first[n + 1];
    memset(first, 0, sizeof(first));
    int second[n + 1];
    memset(second, 0, sizeof(second));
    for (auto trustTmp : trust)
    {
        first[trustTmp[0]]++;
        second[trustTmp[1]]++;

        if (second[trustTmp[1]] == n - 1 && first[trustTmp[1]] == 0)
        {
            if (res == -1)
            {
                res = trustTmp[1];
            }
            else
            {
                res = -1;
                break;
            }
        }

        if (res == trustTmp[0])
        {
            res = -1;
            break;
        }
    }

    return res;
}
/*
 * @Author: 辜思学
 * @Description: 2244. 完成所有任务需要的最少轮数
 * @Date: 2024-05-14 23:57:19
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 使用 map 存储每种类型任务的个数，如果存在 1 个的则不能完成，
 * 否则先拆分成 3 个一组，不剩下则直接完成，还剩下 1 个则配合一组（一定有、否则仅有 1 个）变成 2+2 两组，剩下 2 个直接开新租，总结如果还剩下则直接加一组即可
 */
int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> mapCount;

    for (int task : tasks)
    {
        mapCount[task]++;
    }

    int res = 0;
    for (auto &[t, c] : mapCount)
    {
        if (c == 1)
        {
            return -1;
        }

        res += c / 3 + min(1, c % 3);
    }

    return res;
}
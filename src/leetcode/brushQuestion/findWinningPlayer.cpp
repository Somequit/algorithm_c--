/*
 * @Author: 辜思学
 * @Description: 3175. 找到连续赢 K 场比赛的第一位玩家
 * @Date: 2024-10-24 23:30:40
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 找到 skill[i] 的最大值下标 maxIndex，如果 k 小于 maxIndex 则可能为 maxIndex 之前的元素，否则一定为 maxIndex
 * 如果为 maxIndex 之前的元素，则直接从 0 开始对比，如果在 maxIndex 之前连续赢 k 次则为结果，否则答案也是 maxIndex
 * 优化：不需要找到 maxIndex，仅需要一次遍历 skills 数组，如果连续赢 k 次就返回结果，否则返回最后得到的赢下来的下标其实就是 maxIndex
 */
int findWinningPlayer(vector<int> &skills, int k)
{
    // int maxIndex = 0;
    // for (int i = 1; i < skills.size(); i++)
    // {
    //     if (skills[maxIndex] < skills[i])
    //     {
    //         maxIndex = i;
    //     }
    // }

    // if (k >= maxIndex)
    // {
    //     return maxIndex;
    // }

    int winCount = 0;
    int winIndex = 0;
    // for (int i = 1; i < maxIndex; i++)
    for (int i = 1; i < skills.size(); i++)
    {
        if (skills[winIndex] < skills[i])
        {
            winCount = 0;
            winIndex = i;
        }
        winCount++;
        if (winCount == k)
        {
            return winIndex;
        }
    }
    return winIndex;
}
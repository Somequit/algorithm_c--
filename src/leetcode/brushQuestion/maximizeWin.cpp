/*
 * @Author: 辜思学
 * @Description: 2555. 两个线段获得的最多奖品
 * @Date: 2024-09-11 11:10:58
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 首先最优解的两条线如果有交集，则改成没有交集、即如第二条线后移，结果不会变，
 * 然后预处理以每个点为开头可以获得多少奖品，
 * 最后倒序枚举第一个点的开头，使用 双指针 + 后缀最大值，方式求出后一条线在没有交集情况下、最多可获得的奖品数
 */
int maximizeWin(vector<int> &prizePositions, int k)
{
    int len = prizePositions.size();
    int startNums[len];
    memset(startNums, 0, sizeof(startNums));

    for (int left = 0, right = 1; left < len; left++)
    {
        while (right < len && prizePositions[right] - prizePositions[left] <= k)
        {
            right++;
        }
        startNums[left] = right - left;
    }

    int res = startNums[len - 1];
    int maxSecondNums = 0;
    for (int first = len - 2, second = len - 1; first >= 0; first--)
    {
        while (prizePositions[second] - prizePositions[first] > k)
        {
            maxSecondNums = maxSecondNums < startNums[second] ? startNums[second] : maxSecondNums;
            second--;
        }

        res = res < (maxSecondNums + startNums[first]) ? (maxSecondNums + startNums[first]) : res;
    }

    return res;
}
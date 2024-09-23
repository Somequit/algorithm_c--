/*
 * @Author: 辜思学
 * @Description: 1014. 最佳观光组合
 * @Date: 2024-09-23 07:58:06
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 倒序枚举 i 将 i 后面的元素按规则放入大顶堆中，每次找到最大值即为当前 i 与后面的最大得分，
 * 由于得分位：评分之和 减去 距离，因此与 i+1 评分为 和-1、i+2 评分为 和-2...，
 * 因此可转化为，放入大顶堆时从后往前是 ...+2、+1、+0，取出最大值再减去对应值即可
 * 优化：由于仅需要最大值，因此每次直接维护最大值，不需要大顶堆
 */
int maxScoreSightseeingPair(vector<int> &values)
{
    int res = 0;
    
    for (int i = values.size() - 2,count = 1,maxValue = values[values.size() - 1]; i >= 0; i--,count++)
    {
        res = max(res, values[i] + maxValue - count);
        maxValue = max(maxValue, values[i] + count);
    }

    return res;
}
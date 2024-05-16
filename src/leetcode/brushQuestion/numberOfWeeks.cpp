/*
 * @Author: 辜思学
 * @Description: 1953. 你可以工作的最大周数
 * @Date: 2024-05-16 09:51:32
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 排序 milestones，
 * 如果最大值 小于等于 其他总和+1，则全部可以完成，其他总和先两两配对，直到与最大值/最大值-1 相等
 * 否则最多完成：其他总和*2+1，可将最大值和其他总和一一间隔完成，直到其他总和全部消耗完成，最大值还可以再做一周
 */
long long numberOfWeeks(vector<int> &milestones)
{
    int len = milestones.size();
    // 特判仅有一个任务
    if (len == 1)
    {
        return 1L;
    }

    sort(milestones.begin(), milestones.end());

    long long maxValue = milestones[len - 1];
    long long otherSum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        otherSum += milestones[i];
    }

    if (maxValue <= otherSum + 1)
    {
        return maxValue + otherSum;
    }
    else
    {
        return otherSum * 2L + 1L;
    }
}
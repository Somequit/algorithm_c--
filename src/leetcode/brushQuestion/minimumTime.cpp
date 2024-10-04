/*
 * @Author: 辜思学
 * @Description: 2187. 完成旅途的最少时间
 * @Date: 2024-10-05 07:36:38
 */

#include <bits/stdc++.h>

using namespace std;

bool doMinimumTime(vector<int> time, int totalTrips, long long ansTime)
{
    long long curTrips = 0;
    for (auto curTime : time)
    {
        curTrips += ansTime / curTime;
    }

    return curTrips >= totalTrips;
}

/**
 * 由于超过最小时间均可以完成不少于 totalTrips 次旅途，因此直接二分答案，区间为 [1, totalTrips*(time[i])]
 */
long long minimumTime(vector<int> &time, int totalTrips)
{
    long long left = 1;
    long long right = 1LL * totalTrips * time[0];
    long long res = right;
    while (left <= right)
    {
        long long mid = ((right - left) >> 1) + left;
        if (doMinimumTime(time, totalTrips, mid))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}
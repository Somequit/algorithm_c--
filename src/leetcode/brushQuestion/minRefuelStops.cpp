/*
 * @Author: 辜思学
 * @Description: 871. 最低加油次数
 * @Date: 2024-10-07 11:56:41
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 每次将行进路径上所有加油站放入大顶堆中，找到加油最多的站加上油，行进路径变大进而将更多加油站放入大顶堆，直到终点即可
 */
int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int res = 0;
    int curFuel = startFuel;
    priority_queue<int> minFuelHeap;

    int stationStart = 0;
    while (stationStart < stations.size() && stations[stationStart][0] <= curFuel)
    {
        minFuelHeap.emplace(stations[stationStart][1]);
        stationStart++;
    }

    while (curFuel < target && minFuelHeap.size())
    {
        curFuel += minFuelHeap.top();
        minFuelHeap.pop();

        while (stationStart < stations.size() && stations[stationStart][0] <= curFuel)
        {
            minFuelHeap.emplace(stations[stationStart][1]);
            stationStart++;
        }

        res++;
    }

    return curFuel < target ? -1 : res;
}
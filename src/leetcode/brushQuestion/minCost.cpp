/*
 * @Author: 辜思学
 * @Description: 1928. 规定时间内到达终点的最小花费
 * @Date: 2024-10-03 16:47:53
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 带限制的 DIJ：DIJ 求最小的 passingFees 费用，同时保证到每个点的时间均小于等于 maxTime
 */
int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
{
    // 建图
    int n = passingFees.size();
    vector<pair<int, int>> graph[n];
    for (auto edge : edges)
    {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
    }

    // 初始化 minCost 与 minTime
    vector<int> minCost(n + 1, INT_MAX);
    minCost[0] = minCost[0];
    vector<int> minTime(n + 1, INT_MAX);
    minTime[0] = 0;

    // 最小堆优化 DIJ，<费用、当前点、花费时间>
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    minHeap.emplace(passingFees[0], 0, 0);
    while (minHeap.size())
    {
        auto [hCost, hId, hTime] = minHeap.top();
        minHeap.pop();
        if (hId == n - 1)
        {
            return hCost;
        }

        for (auto [nId, midTime] : graph[hId])
        {
            int nCost = hCost + passingFees[nId];
            int nTime = hTime + midTime;

            // 限制时间一定小于等于 maxTime
            if (nTime > maxTime)
            {
                continue;
            }

            // 到目标点要么时间更小、要么花费更小
            if (nCost < minCost[nId] || nTime < minTime[nId])
            {
                minCost[nId] = nCost;
                minTime[nId] = nTime;
                minHeap.emplace(nCost, nId, nTime);
            }
        }
    }

    return -1;
}
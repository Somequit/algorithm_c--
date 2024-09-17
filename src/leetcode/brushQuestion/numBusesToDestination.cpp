/*
 * @Author: 辜思学
 * @Description: 815. 公交路线
 * @Date: 2024-09-17 10:46:02
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 建图 + BFS
 * 每个 routes[i] 看做一个点，routes[i] 内有相同的值则两点可互通、边长为 1，建一张无向图
 * 判断起点与终点都在哪些 routes[i]点 内，最后求得就是任意起点 routes[i] 到任意终点的最短路径（结果加一）
 * 由于边长均为 1，将起点全加入跑 BFS 即可
 */
int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    // 特判 同一个位置不用走
    if (source == target)
    {
        return 0;
    }

    int pointNum = routes.size();

    // 建图
    vector<int> routesGraph[pointNum];
    unordered_set<int> routesSet[pointNum];
    vector<int> sourceRoutes;
    unordered_set<int> targetRoutes;

    for (int i = 0; i < routes.size(); i++)
    {
        for (auto routeValue : routes[i])
        {
            // 起点与终点都在哪些 routes[i]点 内
            if (routeValue == source)
            {
                sourceRoutes.push_back(i);
            }
            if (routeValue == target)
            {
                targetRoutes.emplace(i);
            }

            // 建立无向图
            for (int j = 0; j < i; j++)
            {
                if (routesSet[j].count(routeValue))
                {
                    routesGraph[i].push_back(j);
                    routesGraph[j].push_back(i);
                }
            }
        }
        // 同一辆车直接从 source 到 target
        if (sourceRoutes.size() > 0 && targetRoutes.size() > 0 && targetRoutes.count(sourceRoutes.back()))
        {
            return 1;
        }

        routesSet[i].insert(routes[i].begin(), routes[i].end());
    }

    int res = 1e9;
    // BFS
    queue<pair<int, int>> queue;
    bool vis[pointNum];
    memset(vis, false, sizeof(vis));
    for (auto sourceRoute : sourceRoutes)
    {
        queue.emplace(sourceRoute, 1);
        vis[sourceRoute] = true;
    }

    bool flag = false;
    while (!queue.empty())
    {
        pair<int, int> current = queue.front();
        queue.pop();
        for (auto next : routesGraph[current.first])
        {
            if (targetRoutes.count(next))
            {
                res = min(res, current.second + 1);
                flag = true;
                break;
            }
            if (!vis[next])
            {
                vis[next] = true;
                queue.emplace(next, current.second + 1);
            }
        }

        if (flag)
        {
            break;
        }
    }

    return res == 1e9 ? -1 : res;
}
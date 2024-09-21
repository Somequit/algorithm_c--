/*
 * @Author: 辜思学
 * @Description: 2374. 边积分最高的节点
 * @Date: 2024-09-21 09:19:36
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 记录每个点的边积分，遍历一遍找到结果
 */
int edgeScore(vector<int> &edges)
{
    int len = edges.size();
    long long score[len];
    memset(score, 0, sizeof(score));

    for (int i = 1; i < len; i++)
    {
        score[edges[i]] += i;
    }

    int res = 0;
    for (int i = 1; i < len; i++)
    {
        if (score[i] > score[res])
        {
            res = i;
        }
    }
    return res;
}
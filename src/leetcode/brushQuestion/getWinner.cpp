/*
 * @Author: 辜思学
 * @Description: 1535. 找出数组游戏的赢家
 * @Date: 2024-05-19 08:50:55
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 先找到 arr 最大值，然后模拟比赛，当没有循环到最大值时达到条件则返回结果，否则直接返回最大值
 */
int getWinner(vector<int> &arr, int k)
{
    int n = arr.size();

    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = max(maxNum, arr[i]);
    }

    int res = arr[0];
    int winCount = 0;
    for (int i = 1; i < n; i++)
    {
        if (res > arr[i])
        {
            winCount++;
        }
        else
        {
            res = arr[i];
            winCount = 1;
        }

        if (res == maxNum || winCount == k)
        {
            break;
        }
    }

    return res;
}
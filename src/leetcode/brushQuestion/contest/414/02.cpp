/*
 * @Author: 辜思学
 * @Description: Q2. 范围内整数的最大得分
 * @Date: 2024-09-08 10:31:03
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 二分答案
 */
int maxPossibleScore(vector<int> &start, int d)
{
    sort(start.begin(), start.end());
    int n = start.size();

    int left = 0;
    int right = start[n - 1] + d - start[0];
    int res = 0;
    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;

        if (doMaxPossibleScore(start, d, mid))
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return res;
}

bool doMaxPossibleScore(vector<int> &start, int d, int score)
{
    int n = start.size();
    long long prevNum = start[0];
    for (int i = 1; i < n; i++)
    {
        if (prevNum + score < start[i])
        {
            prevNum = start[i];
        }
        else if (prevNum + score <= start[i] + d)
        {
            prevNum += score;
        }
        else
        {
            return false;
        }
    }
    return true;
}
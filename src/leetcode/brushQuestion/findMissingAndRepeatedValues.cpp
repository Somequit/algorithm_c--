/*
 * @Author: 辜思学
 * @Description: 2965. 找出缺失和重复的数字
 * @Date: 2024-05-31 11:39:16
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 数组计数即可
 */
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    int count[n * n];
    memset(count, 0, sizeof(count));

    vector<int> res(2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count[grid[i][j] - 1]++;
            if (count[grid[i][j] - 1] == 2)
            {
                res[0] = grid[i][j];
            }
        }
    }

    for (int i = 0; i < n * n; i++)
    {
        if (count[i] == 0)
        {
            res[1] = i + 1;
            break;
        }
    }

    return res;
}
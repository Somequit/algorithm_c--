/*
 * @Author: 辜思学
 * @Description: 994. 腐烂的橘子
 * @Date: 2024-05-13
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 多源 BFS
 */
int orangesRotting(vector<vector<int>> &grid)
{
    int res = 0;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> badGrid;
    int freshCount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                freshCount++;
            }
            else if (grid[i][j] == 2)
            {
                badGrid.emplace_back(i, j);
            }
        }
    }

    while (freshCount != 0 && !badGrid.empty())
    {
        res++;
        vector<pair<int, int>> badGridTemp;

        for (auto &[x, y] : badGrid)
        {
            for (auto d : dir)
            {
                int xx = x + d[0];
                int yy = y + d[1];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1)
                {
                    grid[xx][yy] = 2;
                    freshCount--;
                    badGridTemp.emplace_back(xx, yy);
                }
            }
        }

        badGrid = move(badGridTemp);
    }

    return freshCount == 0 ? res : -1;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << orangesRotting(grid) << endl;
    return 0;
}
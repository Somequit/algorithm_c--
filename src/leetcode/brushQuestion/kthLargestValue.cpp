/*
 * @Author: 辜思学
 * @Description: 1738. 找出第 K 大的异或坐标值
 * @Date: 2024-05-26 23:10:25
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 由于异或性质，xorMat[i][j] = matrix[i][j] ^ xorMat[i-1][j] ^ xorMat[i][j-1] ^ xorMat[i-1][j-1]，获取所有元素后放入最多存 k 个元素的大顶堆
 */
int kthLargestValue(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int xorMat[m + 1][n + 1];
    memset(xorMat, 0, sizeof(xorMat));
    priority_queue<int, vector<int>, greater<int>> heapGreapK;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            xorMat[i][j] = matrix[i - 1][j - 1] ^ xorMat[i - 1][j] ^ xorMat[i][j - 1] ^ xorMat[i - 1][j - 1];
            heapGreapK.emplace(xorMat[i][j]);
            if (heapGreapK.size() > k)
            {
                heapGreapK.pop();
            }
        }
    }

    return heapGreapK.top();
}

int main()
{
    vector<vector<int>> matrix = {{5, 2}, {1, 6}};
    cout << kthLargestValue(matrix, 1) << endl;
    return 0;
}

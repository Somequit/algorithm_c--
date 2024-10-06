/*
 * @Author: 辜思学
 * @Description: 134. 加油站
 * @Date: 2024-10-06 22:24:29
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 每个点用汽油减去消耗，代表剩余油量 surplus，再将其复制一份放在后面(可以新增数组，而是使用 gas-cost 模拟)，
 * 从 下标0 开始找开头位置，然后依次与后面的 surplus 相加，过程中不能等于负数、否则直接更新开头到下一个位置，直到结尾与开头长度为一圈或者不足一圈（不存在解）
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    // int surplus[n << 1];
    // for (int i = 0; i < n; i++)
    // {
    //     surplus[i] = gas[i] - cost[i];
    //     surplus[i + n] = surplus[i];
    //     // cout << surplus[i] << " ";
    // }
    // cout << endl;

    int start = 0;
    int curGas = 0;
    for (int i = 0; i < (n << 1); i++)
    {
        curGas += gas[i % n] - cost[i % n];
        if (start >= n)
        {
            return -1;
        }
        else if (curGas < 0)
        {
            start = i + 1;
            curGas = 0;
        }
        else if (i - start + 1 == n)
        {
            return start;
        }

        // cout << i << " " << start << " " << curGas << " " << endl;
    }
    return -1;
}
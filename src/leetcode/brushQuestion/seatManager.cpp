/*
 * @Author: 辜思学
 * @Description: 1845. 座位预约管理系统
 * @Date: 2024-09-30 18:10:03
 */

#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<>> minHeap;
/**
 * 标准小顶堆
 * 如果不保证 unreserve 调用前一定为被预约状态则使用 set
 */
void SeatManager(int n)
{
    for (int i = 1; i <= n; i++)
    {
        minHeap.emplace(i);
    }
}

int reserve()
{
    int res = minHeap.top();
    minHeap.pop();
    return res;
}

void unreserve(int seatNumber)
{
    minHeap.emplace(seatNumber);
}
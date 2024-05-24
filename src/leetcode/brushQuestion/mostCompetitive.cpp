/*
 * @Author: 辜思学
 * @Description: 1673. 找出最具竞争力的子序列
 * @Date: 2024-05-24 21:06:34
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 优先队列每次弹出（值最小，下标最小）的元素，如果 下标 i 在区间 [l, r] 之间则可以作为结果当前元素，随后更新 l=i+1，r++ 即可，初始 l=0，r=n-k
 */
vector<int> mostCompetitive(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heapNumIndex;

    int n = nums.size();
    int left = 0;
    int right = n - k;
    for (int i = left; i < right + 1; i++)
    {
        heapNumIndex.emplace(pair(nums[i], i));
    }
    vector<int> res(k);
    for (int i = 0; i < k; i++)
    {
        pair<int, int> numIndex = heapNumIndex.top();
        heapNumIndex.pop();
        while (numIndex.second < left || numIndex.second > right)
        {
            numIndex = heapNumIndex.top();
            heapNumIndex.pop();
        }

        res[i] = numIndex.first;
        left = numIndex.second + 1;
        right++;
        if (right < n)
        {
            heapNumIndex.emplace(pair(nums[right], right));
        }
    }

    return res;
}
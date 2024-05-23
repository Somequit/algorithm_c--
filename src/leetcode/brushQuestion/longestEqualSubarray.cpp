/*
 * @Author: 辜思学
 * @Description: 2831. 找出最长等值子数组
 * @Date: 2024-05-23 23:49:24
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 值放入 map 的 key，value 放入对应值的递增的下标，对每个值的下标滑动窗口
 */
int longestEqualSubarray(vector<int> &nums, int k)
{
    unordered_map<int, vector<int>> mapNumIndex;

    for (int i = 0; i < nums.size(); i++)
    {
        mapNumIndex[nums[i]].push_back(i);
    }

    int res = 1;
    for (auto &entry : mapNumIndex)
    {

        int deCount = 0;
        for (int left = 0, right = 1; right < entry.second.size(); right++)
        {
            deCount += entry.second[right] - entry.second[right - 1] - 1;
            while (deCount > k)
            {
                deCount -= entry.second[left + 1] - entry.second[left] - 1;
                left++;
            }

            res = max(res, right - left + 1);
        }
    }

    return res;
}
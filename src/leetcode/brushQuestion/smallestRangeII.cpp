/*
 * @Author: 辜思学
 * @Description: 910. 最小差值 II
 * @Date: 2024-10-21 00:13:15
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * nums 升序，枚举 [0,n-2] 的每个 i，让 [0,i] 均 +k，[i+1,n-1] 均 -k，求得所有 i 中 max(nums[n-1]-k, nums[i]+k)-min(nums[0]+k, nums[i+1]-k) 的最小值
 * 其次如果 [0,n-1] 均 +k/-k 则还需要比较上述结果与 num[n-1]-nums[0] 的值
 */
int smallestRangeII(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int res = nums[n - 1] - nums[0];
    for (int i = 0; i < n - 1; i++)
    {
        res = min(res, max(nums[n - 1] - k, nums[i] + k) - min(nums[0] + k, nums[i + 1] - k));
    }

    return res;
}
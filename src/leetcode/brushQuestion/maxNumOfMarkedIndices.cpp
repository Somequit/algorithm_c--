/*
 * @Author: 辜思学
 * @Description: 2576. 求出最多标记下标
 * @Date: 2024-09-12 10:31:33
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 首先由于标记与顺序无关，先升序排序，
 * 然后最多标记个数则是偶数个全部标记、即 n/2 个 i 与 j，奇数个全部标记少一个、即 （n-1）/2 个 i 与 j，
 * 接着按照规则，i 从小到大是最优解，同时 j 从后一半（奇数则后一半多一个/少一个均可，不过少一个更优）开始最优，
 * 最后使用双指针的方式，i 递增，直到 i/j 用完
 */
int maxNumOfMarkedIndices(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int res = 0;
    int len = nums.size();
    for (int i = 0, j = len / 2; i < len / 2 && j < len; i++, j++)
    {
        while (j < len && 2 * nums[i] > nums[j])
        {
            j++;
        }

        if (j < len)
        {
            res += 2;
        }
    }

    return res;
}
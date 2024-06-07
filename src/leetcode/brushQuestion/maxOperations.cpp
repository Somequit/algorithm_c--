/*
 * @Author: 辜思学
 * @Description: 3040. 相同分数的最大操作数目 II
 * @Date: 2024-06-08 03:15:37
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 2000

int res = 1;
bool memo[MAX_NUM][MAX_NUM];
/**
 * 第一次删除的三种不同操作可获得三个分数，将每种不同的分数进行记忆化搜索操作
 */
int maxOperations(vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        return 1;
    }

    int n = nums.size();

    unordered_set<int> setScore = {nums[0] + nums[1], nums[n - 1] + nums[n - 2], nums[0] + nums[n - 1]};
    for (auto &score : setScore)
    {

        memset(memo, false, sizeof(memo));
        memoryDfs(score, 0, n - 1, 0, nums);
    }

    return res;
}

void memoryDfs(int score, int left, int right, int count, vector<int> &nums)
{
    res = max(res, count);
    if (right - left < 1 || memo[left][right])
    {
        return;
    }
    memo[left][right] = true;

    if (nums[left] + nums[left + 1] == score)
    {
        memoryDfs(score, left + 2, right, count + 1, nums);
    }
    if (nums[left] + nums[right] == score)
    {
        memoryDfs(score, left + 1, right - 1, count + 1, nums);
    }
    if (nums[right] + nums[right - 1] == score)
    {
        memoryDfs(score, left, right - 2, count + 1, nums);
    }
}
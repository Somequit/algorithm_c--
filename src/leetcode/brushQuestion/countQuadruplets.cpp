/*
 * @Author: 辜思学
 * @Description: 2552. 统计上升四元组
 * @Date: 2024-09-10 13:23:24
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 枚举 j、k 保证 nums[k]<nums[j]，找到 j 左边小于 nums[k] 的个数 left 乘以 k 右边大于 nums[j] 的个数 right
 * 求 left：先固定 j(倒序 j 更方便)，然后 j 右边排序（可加入 map），枚举其小于 nums[j] 的 k，计算出个数即：nums[k]-当前k是枚举的第几个（因为仅包含 1 到 n），将其放入 left[nums[j]][nums[k]] 中，
 * 求 right 与求 left 基本一致，不过可以直接乘以 left 加入最后答案中
 * 时间复杂度：O(n^2*logn)，空间复杂度：O(n^2)
 */
long long countQuadruplets(vector<int> &nums)
{
    // unordered_map<int, int> leftMap;
    int len = nums.size();

    int leftMap[len + 1][len + 1];
    memset(leftMap, 0, sizeof(leftMap));
    // 注意最右边一个元素需要存起来，否则计算个数就不准确
    set<int> numsKSet;
    numsKSet.insert(nums[len - 1]);
    for (int j = len - 3; j > 0; j--)
    {
        int k = j + 1;
        numsKSet.insert(nums[k]);

        int count = 0;
        for (auto numsK : numsKSet)
        {
            count++;
            if (numsK < nums[j])
            {
                // int leftKey = nums[j] * 4000 + numsK;
                // leftMap.emplace(leftKey, numsK - count);
                leftMap[nums[j]][numsK] = numsK - count;
                // cout << "left " << leftKey << " " << numsK - count << endl;
            }
            else
            {
                break;
            }
        }
    }

    long long res = 0L;
    // 降序存储方便降序遍历
    set<int, greater<int>> numsJSet;
    numsJSet.insert(nums[0]);
    for (int k = 2; k < len - 1; k++)
    {
        int j = k - 1;
        numsJSet.insert(nums[j]);

        int count = 0;
        // 降序遍历
        for (auto numsJ : numsJSet)
        {
            count++;
            if (numsJ > nums[k])
            {
                // int leftKey = numsJ * 4000 + nums[k];
                // res += (len - numsJ - count + 1) * (leftMap.count(leftKey) > 0 ? leftMap[leftKey] : 0);
                res += (len - numsJ - count + 1) * leftMap[numsJ][nums[k]];
                // cout << "right " << numsJ << " " << leftKey << endl;
            }
            else
            {
                break;
            }
        }
    }

    return res;
}

/**
 * 优化
 * 可看做求 1324，枚举 j、k 保证 nums[k]<nums[j]，找到 j 左边小于 nums[k] 的个数 left 乘以 k 右边大于 nums[j] 的个数 right
 * 求 left：先固定 j(倒序 j 更方便)，然后 j 右边元素放入 bool 数组中，再求出 left[nums[j]][nums[k]] = left[nums[j]][1]...left[nums[j]][nums[j]-1] 中，
 * nums[k] 存在 bool 数组的元素个数：因为仅包含 1 到 n，因此不存在 bool 数组就 +1，存在就将赋值
 * 求 right 与求 left 基本一致，不过可以直接乘以 left 加入最后答案中
 * 时间复杂度：O(n^2)，空间复杂度：O(n^2)
 */
long long countQuadruplets2(vector<int> &nums)
{
    int len = nums.size();

    int left[len + 1][len + 1];
    memset(left, 0, sizeof(left));

    bool vis[len + 1];
    memset(vis, false, sizeof(vis));
    vis[nums[len - 1]] = true;
    for (int j = len - 3; j > 0; j--)
    {
        vis[nums[j + 1]] = true;
        int count = 0;

        for (int k = 1; k < nums[j]; k++)
        {
            if (vis[k])
            {
                left[nums[j]][k] = count;
            }
            else
            {
                count++;
            }
        }
    }

    long long res = 0L;
    memset(vis, false, sizeof(vis));
    vis[nums[0]] = true;
    for (int k = 2; k < len - 1; k++)
    {
        vis[nums[k - 1]] = true;
        int count = 0;

        for (int j = len; j > nums[k]; j--)
        {
            if (vis[j])
            {
                res += count * left[j][nums[k]];
            }
            else
            {
                count++;
            }
        }
    }
    
    return res;
}
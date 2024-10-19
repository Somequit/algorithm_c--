/*
 * @Author: 辜思学
 * @Description: 3192. 使二进制数组全部等于 1 的最少操作次数 II
 * @Date: 2024-10-19 11:06:49
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 直接从第一位开始到最后一位，如果是 0 则有且仅修改一次，否则不修改即可，修改使用 异或1 更方便
 * 修改下标 i 代表后面全部修改，可以添加一个变量 all=0 代表 [i,n）是否需要修改
 */
int minOperations(vector<int> &nums)
{
    int all = 0;
    int res = 0;
    for (auto num : nums)
    {
        num ^= all;
        if (num == 0)
        {
            all ^= 1;
            num = 1;
            res++;
        }
    }

    return res;
}
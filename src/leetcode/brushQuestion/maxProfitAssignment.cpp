/*
 * @Author: 辜思学
 * @Description: 826. 安排工作以达到最大收益
 * @Date: 2024-05-17 21:01:16
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 将 difficulty 和 profit 放一起，同时按照 difficulty 升序，worker 单独升序，
 * 双指针循环 difficulty 与 worker，每次记录最大的 profit
 */
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {difficulty[i], profit[i]};
    }

    // 对 vector 里的 pair 比较，pair的 比较规则就是先比较 first，first 相同比较 second
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int res = 0;
    int maxProfit = 0;
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && jobs[j].first <= worker[i])
        {
            maxProfit = max(maxProfit, jobs[j].second);
            j++;
        }

        res += maxProfit;
    }

    return res;
}

int main()
{
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    cout << maxProfitAssignment(difficulty, profit, worker) << endl;
    return 0;
}
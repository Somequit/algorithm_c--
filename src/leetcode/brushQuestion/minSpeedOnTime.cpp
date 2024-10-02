/*
 * @Author: 辜思学
 * @Description: 1870. 准时到达的列车最小时速
 * @Date: 2024-10-02 16:42:57
 */

#include <bits/stdc++.h>

using namespace std;

long long toHour100(double hour)
{
    // 会变成 6 位小数
    string hourStr = to_string(hour);
    // 删除最后 4 位小数
    hourStr = hourStr.substr(0, hourStr.size() - 4);
    // 删除小数点
    hourStr.erase(hourStr.find("."), 1);

    return stoll(hourStr);
}
/**
 * 是否可以在 hour 时间内达到
 */
bool doMinSpeedOnTime(vector<int> &dist, int speed, double hour)
{
    // 用进 1 法将 hour*100 转化为整数
    // long long hour100 = toHour100(hour);
    long long hour100 = round(hour * 100);
    // cout << hour100 << endl;
    // 先减去除最后一段用的整数时间*100
    for (int i = 0; i < dist.size() - 1; i++)
    {
        hour100 -= (dist[i] / speed + min(1, dist[i] % speed)) * 100;
    }

    // 再看 hour 剩下的时间乘速度是否可以跑 dist[dist.size()-1]*100 的距离
    return hour100 * speed >= (long long)dist[dist.size() - 1] * 100;
}
/**
 * 由于速度越大，消耗时间不会减少，因此二分答案即可找到最小速度下、时间小于等于 hour 的值，速度区间为 [1,10^7]，如果速度达到 10^7 时间也大于 hour 则答案为 -1
 * 最后比较时间时 double 比较可能存在问题：
 * 用转化为 string 将 hour*100 转化为整数
 * 先减去除最后一段用的整数时间*100，再看 hour 剩下的时间乘速度是否可以跑 dist[dist.size()-1]*100 的距离
 */
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int res = -1;
    int left = 1;
    int right = 1e7;
    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;
        // 可以在 hour 时间内达到
        if (doMinSpeedOnTime(dist, mid, hour))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}

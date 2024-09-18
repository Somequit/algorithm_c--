/*
 * @Author: 辜思学
 * @Description: 2332. 坐上公交的最晚时间
 * @Date: 2024-09-18 12:37:06
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 遍历每一辆车坐满/乘完，最后一辆车如果没坐满结果就是发车时间，如果坐满了结果就是最后一个人的时间减一就是结果，最后处理结果不能与任意乘客重复即可
 */
int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
{
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    // 最后一辆车发车时间
    int res = buses.back();

    for (int passStart = 0, passStop = 0, busI = 0; passStop < passengers.size() && busI < buses.size(); passStop++)
    {
        while (busI < buses.size() && (buses[busI] < passengers[passStop] || passStop - passStart + 1 > capacity))
        {
            busI++;
            passStart = passStop;
        }

        // cout << passStart << " " << passStop << " " << busI << endl;
        if (busI == buses.size() - 1 && passStop - passStart + 1 == capacity)
        {
            res = passengers[passStop] - 1;
        }
    }
    // cout << res << endl;

    for (int i = passengers.size() - 1; i >= 0; i--)
    {
        if (passengers[i] == res)
        {
            res--;
        }
        else if (passengers[i] < res)
        {
            break;
        }
    }

    return res;
}
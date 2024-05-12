/*
 * @Author: 辜思学
 * @Description: 2391. 收集垃圾的最少总时间
 * @Date: 2024/5/11.
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * 先找到 M、P、G 最后出现的位置，就是该垃圾车最后行驶到的位置，然后加上每个字符串长度即可
 */
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int res = 0;
    int lastIndex[3];
    char garbageChar[3] = {'M', 'P', 'G'};

    for (int i = 0; i < garbage.size(); i++) {
        string garbageTemp = garbage[i];

        for (int j = 0; j < 3; j++) {
//            cout << garbageChar[j] << " " << garbageTemp.find(garbageChar[j]) << endl;
            if (garbageTemp.find(garbageChar[j]) != string::npos) {
//                cout << garbageTemp << " " << j << endl;
                lastIndex[j] = i;
            }
        }

        res += garbageTemp.size();
    }

//    for (int i : lastIndex) {
//        cout << i << endl;
//    }
//    cout << res << endl;

    for (int i = 1; i < garbage.size(); i++) {
        for (int j : lastIndex) {
            if (j >= i) {
                res += travel[i - 1];
            }
        }
    }

    return res;
}
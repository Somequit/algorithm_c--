/*
 * @Author: 辜思学
 * @Description: 2105. 给植物浇水 II
 * @Date: 2024/5/9
 */

#include <iostream>
#include <vector>

using namespace std;

// 一次遍历，双指针类似
int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int res = 0;

    int curCapacityA = capacityA;
    int curCapacityB = capacityB;
    for (int i = 0, j = plants.size() - 1; i <= j; i++, j--) {
        if (i == j) {
            if (max(curCapacityA, curCapacityB) < plants[i]) {
                res++;
            }

        } else {
            if (curCapacityA < plants[i]) {
                res++;
                curCapacityA = capacityA - plants[i];

            } else {
                curCapacityA -= plants[i];
            }

            if (curCapacityB < plants[j]) {
                res++;
                curCapacityB = capacityB - plants[j];

            } else {
                curCapacityB -= plants[j];
            }
        }
    }

    return res;
}

int main() {
    vector<int> plants = {0, 1, 2, 3, 4};
    int i = 0;
    cout << minimumRefill(plants, 5, 5) << endl;
    return 0;
}
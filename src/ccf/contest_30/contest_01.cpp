/*
 * @Author: 辜思学
 * @Description: 重复局面
 * @Date: 2024-05-23 17:05:11
 */

#pragma GCC optimize(2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
using i64 = long long;
using ui64 = unsigned long long;
using i128 = __int128;
#define inf (int)0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#ifdef DEBUG
#include "debug.h"
#else
#define dbg(...) void(0)
#endif

// const int N = 2e5 + 5;
// const int M = 1e5 + 5;
// const int mod = 998244353;
// const int mod = 1e9 + 7;
// template <typename T> T ksm(T a, i64 b) { T ans = 1; for (; b; a = 1ll * a * a, b >>= 1) if (b & 1) ans = 1ll * ans * a; return ans; }
// template <typename T> T ksm(T a, i64 b, T m = mod) { T ans = 1; for (; b; a = 1ll * a * a % m, b >>= 1) if (b & 1) ans = 1ll * ans * a % m; return ans; }

void work()
{
    int n;
    cin >> n;

    string chessType = "*kqrbnpKQRBNP";
    unordered_map<string, int> mapCount;
    int res[n];
    for (int i = 0; i < n; i++)
    {
        string chessArr;
        for (int j = 0; j < 8; j++)
        {
            string chess;
            cin >> chess;

            chessArr += chess;
        }

        mapCount[chessArr] = mapCount[chessArr] + 1;
        res[i] = mapCount[chessArr];
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.in", "r", stdin);
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    // cin >> Case;
    while (Case--)
    {
        work();
    }
    return 0;
}
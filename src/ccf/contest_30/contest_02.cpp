/*
 * @Author: 辜思学
 * @Description: 矩阵运算
 * @Date: 2024-05-23 17:44:16
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
    int d;
    cin >> n >> d;

    int q[n][d];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> q[i][j];
        }
    }
    int k[n][d];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> k[i][j];
        }
    }
    int v[n][d];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cin >> v[i][j];
        }
    }
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    i64 res[n][d];
    memset(res, 0, sizeof(res));

    i64 kv[d][d];
    memset(kv, 0, sizeof(kv));
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int l = 0; l < n; l++)
            {
                kv[i][j] += k[l][i] * v[l][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int l = 0; l < d; l++)
            {
                res[i][j] += w[i] * q[i][l] * kv[l][j];
            }
        }
    }

    // i64 kSum[n];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         kSum[j] = 0;
    //         for (int l = 0; l < d; l++)
    //         {
    //             kSum[j] += q[i][l] * k[j][l];
    //         }
    //     }

    //     for (int l = 0; l < d; l++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             res[i][l] += kSum[j] * v[j][l];
    //         }
    //         res[i][l] *= w[i];
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cout << res[i][j] << " \n"[j == d - 1];
        }
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
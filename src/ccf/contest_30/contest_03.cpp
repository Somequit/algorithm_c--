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

char hexChar[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
int hexToDec(char h, char l)
{
    int res = 0;
    for (int i = 0; i < 16; i++)
    {
        if (h == hexChar[i])
        {
            res += i * 16;
        }
        if (l == hexChar[i])
        {
            res += i;
        }
    }
    return res;
}
void strRecursion(string &res, int len, int o, int l)
{
    // cout << "o:" << o << " l:" << l << endl;
    int nextIndex = len - o * 2;
    for (int i = 0; i < l; i++)
    {
        res += res[nextIndex++];
        res += res[nextIndex++];
        if (nextIndex == len)
        {
            nextIndex -= o * 2;
        }
    }
}
void work()
{
    int n;
    string origin;
    cin >> n;
    int len = (n + 7) / 8;
    for (int i = 0; i < len; i++)
    {
        string tmp;
        cin >> tmp;
        origin += tmp;
    }
    // cout << "origin:" << origin << endl;
    // cout << "origin.length():" << origin.length() << endl;

    string res;
    bool first = true;
    for (int i = 0; i < origin.length();)
    {
        string pw;
        pw += origin[i++];
        pw += origin[i++];

        if (first)
        {
            int pwInt = hexToDec(pw[0], pw[1]);
            if (pwInt < 128)
            {
                first = false;
            }
            continue;
        }

        int pwInt = hexToDec(pw[0], pw[1]);
        // cout << "i:" << i << " pw:" << pw << " pwInt:" << pwInt << endl;
        // cout << "res:" << res << endl;

        if (pwInt % 4 == 0)
        {
            pwInt >>= 2;
            if (pwInt < 60)
            {
                pwInt++;
                for (int j = 0; j < pwInt; j++)
                {
                    res += origin[i++];
                    res += origin[i++];
                }
                // cout << "res:" << res << endl;
            }
            else
            {
                pwInt -= 59;
                string pwCur;
                int pwCurInt = 1;
                for (int j = 0; j < pwInt; j++)
                {
                    int pwIntTmp = hexToDec(origin[i], origin[i + 1]);
                    pwCurInt += (pwIntTmp << (8 * j));
                    i += 2;
                }
                // cout << "pwCur:" << pwCur << " pwCurInt:" << pwCurInt << endl;
                for (int j = 0; j < pwCurInt; j++)
                {
                    res += origin[i++];
                    res += origin[i++];
                }
            }
        }
        else if (pwInt % 4 == 1)
        {
            int l = (pwInt >> 2) % 8 + 4;

            string pwCur;
            int pwCurInt = hexToDec(origin[i], origin[i + 1]);
            i += 2;
            int o = (((pwInt >> 5) % 8) << 8) + pwCurInt;

            strRecursion(res, res.length(), o, l);
        }
        else
        {
            int l = (pwInt >> 2) + 1;
            int o = 0;
            for (int j = 0; j < 2; j++)
            {
                o += hexToDec(origin[i], origin[i + 1]) << (8 * j);
                i += 2;
            }

            strRecursion(res, res.length(), o, l);
        }
    }

    for (int i = 0; i < res.length(); i += 16)
    {
        int lastLen = res.length() - i;
        cout << res.substr(i, min(16, lastLen)) << endl;
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
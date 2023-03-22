/**
 * @file 5.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-19
 * @version 0.1
 * @brief csp competition
 * @copyright Copyright (c) 2023
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
// #define file(x) freopen(#x".in", "r", stdin); //freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
int q, n, m;
int square(int a) { return a * a; }
int main()
{
    ios::sync_with_stdio(false);
    // file(data);
    cin >> q;
    // q = 1;
    rep(qi, 1, q)
    {
        cin >> n >> m;
        int x = 1, y = 1;
        int xl = 1, xr = n, yl = 1, yr = n;
        int d=0; // 0123
        for (; m > 1; --m)
        {
            switch (d)
            {
            case 0:
            {
                if (x == xr)
                {
                    ++d;
                    ++y;
                    ++yl;
                }
                else
                {
                    ++x;
                }
                break;
            }
            case 1:
            {
                if (y == yr)
                {
                    ++d;
                    --x;
                    --xr;
                }
                else
                {
                    ++y;
                }
                break;
            }
            case 2:
            {
                if (x == xl)
                {
                    ++d;
                    --y;
                    --yr;
                }
                else
                {
                    --x;
                }
                break;
            }
            case 3:
            {
                if (y == yl)
                {
                    d = 0;
                    ++x;
                    ++xl;
                }
                else
                {
                    --y;
                }
                break;
            }
            }
        }
        cout << y << ' ' << x << endl;
    }
    return 0;
}
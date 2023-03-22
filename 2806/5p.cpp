/**
 * @file 5p.cpp
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
#define file(x)                                                                \
    freopen(#x ".in", "r", stdin);                                             \
    freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)

int main() {
    ios::sync_with_stdio(false);
    file(data);
    int q, n, x;
    cin >> q;
    rep(qi, 1, q) {
        cin >> n >> x;
        if (n % 2 && x == n * n) {
            cout << n / 2 + 1 << ' ' << n / 2 + 1 << endl;
        }
        int tmp = 0;
        rep(i, 1, n / 2) {
            int nn = n - (i - 1) * 2;
            if (x <= tmp + nn - 1) {
                cout << i << " " << i + x - tmp - 1 << endl;
                break;
            } else
                tmp += nn - 1;
            if (x <= tmp + nn - 1) {
                cout << i + x - tmp - 1 << " " << n - i + 1 << endl;
                break;
            } else
                tmp += nn - 1;
            if (x <= tmp + nn - 1) {
                cout << n - i + 1 << " " << n - x + tmp - i + 2 << endl;
                break;
            } else
                tmp += nn - 1;
            if (x <= tmp + nn - 1) {
                cout << n - x + tmp - i + 2 << " " << i << endl;
                break;
            } else
                tmp += nn - 1;
        }
    }
    return 0;
}
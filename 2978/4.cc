/**
 * @file 4.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-06
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2023
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define file(x)                  \
  freopen(#x ".in", "r", stdin); \
  freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
const int maxn = 1e4 + 1;
int n, odd[maxn], even[maxn], io, ie, a;
bool is_even[maxn];
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  rep(i, 1, n) {
    cin >> a;
    if (a & 1)
      odd[io++] = a;
    else {
      even[ie++] = a;
      is_even[i] = true;
    }
  }
  sort(odd, odd + io);
  sort(even, even + ie);
  io = 0, ie = 0;
  rep(i, 1, n) {
    if (is_even[i]) {
      cout << even[ie++] << ' ';
    } else
      cout << odd[io++] << ' ';
  }
  return 0;
}
/**
 * @file 5.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-21
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
const int maxn = 5e3 + 2;
const int maxabsval = 1e3;
int n, nums[maxn], sub[maxn], tmp, idx, t, ans;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  while (cin >> nums[++n]) {
    sub[n] = nums[n] - nums[n - 1];
  }
  --n;
  rep(i, 2, n - 1) {
    tmp = sub[i];
    idx = i + 1;
    t = 0;
    while (sub[idx] == tmp) ++t, ++idx;
    ans += t;
  }
  cout << ans;
  return 0;
}
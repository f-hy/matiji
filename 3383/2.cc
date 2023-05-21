/**
 * @file 2.cc
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
const int MAX = 2e6 + 1;
ll n, m, mid, l, r;
ll a[MAX], b[MAX], sum[MAX];
ll check(ll x) {
  for (ll i = 1; i <= n; i++) {
    b[i] = a[i] - x;
    sum[i] = sum[i - 1] + b[i];
  }
  ll y = MAX;
  for (ll i = m; i <= n; i++) {
    y = min(y, sum[i - m]);
    if (sum[i] - y >= 0) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  scanf("%lld %lld", &n, &m);
  l = MAX, r = 0;
  for (ll i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] *= 1000;
    l = min(l, a[i]);
    r = max(r, a[i]);
  }
  while (l != r) {
    mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%lld\n", l);
  return 0;
}
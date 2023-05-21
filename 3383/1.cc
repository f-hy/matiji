/**
 * @file 1.cc
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
const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;
int n, t;
ll a[maxn], sum[maxn], ans, q[maxn];
void msort(int l, int r, ll *a) {
  if (l >= r) return;
  int mid = l + r >> 1;
  msort(l, mid, a), msort(mid + 1, r, a);
  int i = l, j = mid + 1, t = 0;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j]) {
      q[t++] = a[j++];
      ans += mid - i + 1;
      ans %= mod;
    } else
      q[t++] = a[i++];
  }
  while (i <= mid) q[t++] = a[i++];
  while (j <= r) q[t++] = a[j++];
  for (i = l, j = 0; i <= r; ++i, ++j) a[i] = q[j];
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> t;
  rep(i, 1, n) {
    cin >> a[i];
    a[i] -= t;
    sum[i] = sum[i - 1] + a[i];
  }
  msort(0, n, sum);
  cout << ans % mod;
  return 0;
}
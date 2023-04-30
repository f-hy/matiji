/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-30
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
#define P 131
const int maxn = 1e5 + 1;
ll ans[maxn];
int t, n, a[7];
int main() {
  scanf("%d", &n);
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) scanf("%d", &a[j]);
    ans[i] = 0;
    for (int k = 1; k <= 6; k++) {
      int k1 = k + 7, k2 = k + 7, o = 6;
      ll s1 = 0, s2 = 0;
      while (o--) {
        if (k1 % 7 == 0) k1 = 1;
        if (k2 % 7 == 0) k2 = 6;
        s1 = a[k1 % 7] + s1 * P;
        s2 = a[k2 % 7] + s2 * P;
        k1++, k2--;
      }
      ans[i] = max(max(s1, s2), ans[i]);
    }
  }
  sort(ans + 1, ans + n + 1);
  for (int i = 1; i < n; i++)
    if (ans[i] == ans[i + 1]) {
      flag = true;
      printf("found.\n");
      break;
    }
  if (!flag) printf("No\n");
  return 0;
}
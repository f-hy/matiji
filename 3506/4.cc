/**
 * @file 4.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-28
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
const int maxn = 1e5 + 1;
int n, m, a[maxn], fa[maxn];
inline int get(int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa[x]);
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), fa[i] = i;
  while (m--) {
    int f = 0;
    scanf("%d", &f);
    if (f == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      int fx = get(x), fy = get(y);
      if (fx != fy) {
        fa[fy] = fx;
        a[fx] += a[fy];
      }
    } else {
      int x;
      scanf("%d", &x);
      printf("%d\n", a[get(x)]);
    }
  }
  return 0;
}
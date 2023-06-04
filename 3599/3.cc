/**
 * @file 3.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-04
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
const int maxn = 101;
int n, k, ans, fa[maxn];
struct NODE {
  int i, j, c;
  bool operator<(const NODE &t) const { return c < t.c; }
} p[maxn];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
void mer(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) fa[x] = y;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  rep(i, 1, maxn - 1) fa[i] = i;
  cin >> n >> k;
  rep(i, 1, k) cin >> p[i].i >> p[i].j >> p[i].c;
  sort(p + 1, p + 1 + k);
  rep(i, 1, k) if (find(p[i].i) != find(p[i].j)) {
    ans += p[i].c;
    mer(p[i].i, p[i].j);
  }
  cout << ans;
  return 0;
}
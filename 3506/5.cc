/**
 * @file 5.cc
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
int n, m, a, b, f[100005], sz[100005];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) sz[i] = 1, f[i] = i;
  while (m--) {
    cin >> a >> b;
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      f[fa] = fb;
      sz[fb] += sz[fa];
    }
  }
  cin >> a;
  cout << sz[find(a)];
  return 0;
}
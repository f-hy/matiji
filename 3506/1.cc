/**
 * @file 1.cc
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
int n, m, x, y, fa[maxn];
char c;
int main() {
  //   ios::sync_with_stdio(false);
  //   file(data);
  cin >> n >> m;
  while (m--) {
    cin >> c >> x >> y;
    if (c == 'A') {
      fa[x] = y;
      if (fa[y] == x) fa[y] = 0;
    } else {
      int t = x;
      bool ok = false;
      set<int> s;
      while (t != 0) {
        if (t == y) {
          ok = true;
          break;
        }
        t = fa[t];
        if (s.find(t) != s.end()) break;
        s.insert(t);
        if (t == x) break;
      }
      cout << (ok ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
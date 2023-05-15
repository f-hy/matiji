/**
 * @file 4.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-14
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
int n, m;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> m;
  deque<int> a(n * m);
  for (int i = 0; i < n * m; i++) cin >> a[i];
  int k;
  cin >> k;
  k %= n * m;
  for (int i = 0; i < k; i++) {
    a.push_front(a.back());
    a.pop_back();
  }
  for (int i = 0; i < n * m;) {
    cout << a[i] << " ";
    i += 1;
    if (i % m == 0) cout << endl;
  }
  return 0;
}
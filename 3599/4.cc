/**
 * @file 4.cc
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
const int maxn = 1e5 + 1;
int n, c[maxn], ch[maxn];
int lowbit(int x) { return x & -x; }
void add(int x) {
  for (; x < maxn; x += lowbit(x)) ++c[x];
}
int sum(int x) {
  int ret = 0;
  for (; x > 0; x -= lowbit(x)) ret += c[x];
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  int x = 0, maxx = 0;
  rep(i, 1, n) {
    cin >> x;
    if (maxx < x) maxx = x;
    int cnt = sum(x);
    if (cnt == i - 1)
      --ch[maxx];
    else if (cnt == i - 2)
      ++ch[maxx];
    add(x);
  }
  int ans = 1;
  rep(i, 1, n) if (ch[i] > ch[ans]) ans = i;
  cout << ans;
  return 0;
}
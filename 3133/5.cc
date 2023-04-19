/**
 * @file 5.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-19
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
const int maxn = 1e4 + 1;  // 3n,0h
int n, h, ans, dh, dx;
map<int, pair<pair<int, int>, int>, greater<int>>
    hs;  // height descend;min,max,is
map<int, pair<pair<int, int>, int>, greater<int>>::iterator it, pit;
pair<pair<int, int>, int> mmi, t;
int main() {
  ios::sync_with_stdio(false);
  file(data);
  cin >> n;
  hs[0] = {{0, 0}, 0};
  rep(i, 1, n) {
    cin >> h;
    it = hs.find(h);
    if (it == hs.end())
      hs[h] = {{i, i}, 1};
    else {
      mmi = hs[h];
      if (i < mmi.first.first)
        mmi.first.first = i;
      else if (i > mmi.first.second)
        mmi.first.second = i;
      ++mmi.second;
      hs[h] = mmi;
    }
  }
  it = hs.begin();
  dh = it->first;
  while (dh) {
    pit = it;
    ++it;
    dh -= it->first;
    mmi = pit->second;
    dx = mmi.first.second - mmi.first.first - mmi.second + 1;
    ans += (dh * dx);
    t = it->second;
    if (mmi.first.first < t.first.first) t.first.first = mmi.first.first;
    if (mmi.first.second > t.first.second) t.first.second = mmi.first.second;
    t.second += mmi.second;
    it->second = t;
    dh = it->first;
  }
  cout << ans;
  return 0;
}
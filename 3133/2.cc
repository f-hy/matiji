/**
 * @file 2.cc
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
string s;
string subs;
int n;
map<string, int> mp;
pair<string, int> ans;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> s;
  rep(i, 0, n - 2) {
    subs = s.substr(i, 2);
    if (mp.find(subs) == mp.end())
      mp[subs] = 1;
    else
      mp[subs] += 1;
  }
  for (auto &m : mp) {
    if (m.second > ans.second) {
      ans = m;
    }
  }
  cout << ans.first;
  return 0;
}
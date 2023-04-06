/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-06
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
int n, a[maxn], ab, oper;
ll cnta, cntb;
map<int, int> mp;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  rep(i, 1, n) {
    cin >> a[i];
    cnta += a[i];
  }
  rep(i, 1, n) {
    cin >> ab;
    cntb += ab;
    ab = a[i] - ab;
    oper = 1;
    if (ab < 0) {
      oper = -1;
      ab = -ab;
    }
    if (mp.find(ab) == mp.end())
      mp[ab] = oper;
    else
      mp[ab] += oper;
  }
  if (cnta != cntb) {
    cout << "NO";
    return 0;
  }
  for (auto &x : mp) {
    if (x.second != 0) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
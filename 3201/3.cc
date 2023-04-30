/**
 * @file 3.cc
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
string s, ss;
#define no cout << "NO\n";
#define yes cout << "YES\n";
vector<int> v(26), vv(26);
bool flag;
int vi, vii;
int main() {
  ios::sync_with_stdio(false);
  //   file(data);
  while (cin >> s >> ss) {
    if (s.length() != ss.length()) {
      no continue;
    }
    map<char, int> m, mm;
    for (char &c : s) ++m[c];
    for (char &c : ss) ++mm[c];
    if (m.size() != mm.size()) {
      no continue;
    }
    flag = true;
    vi = 0, vii = 0;
    for (auto &i : m) v[vi++] = i.second;
    for (auto &i : mm) vv[vii++] = i.second;
    sort(v.begin(), v.begin() + vi);
    sort(vv.begin(), vv.begin() + vii);
    for (int i = 0; i < vi; ++i) {
      if (v[i] != vv[i]) {
        flag = false;
        no break;
      }
    }
    if (flag) {
      yes
    }
  }
  return 0;
}
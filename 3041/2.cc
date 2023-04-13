/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-13
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
const int maxs = 1e6 + 1;
int cnt;
stack<int> st;
bool match[maxs];
string s;
pii ans({0, 1});
int main() {
  ios::sync_with_stdio(false);
  //   file(data);
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      st.push(i);
    else if (!st.empty())
      match[st.top()] = match[i] = true, st.pop();
  }
  for (int i = 0; i < s.size(); ++i) {
    if (match[i])
      ++cnt;
    else {
      if (cnt > ans.first) {
        ans.first = cnt;
        ans.second = 1;
      } else if (cnt == ans.first) {
        ++ans.second;
      }
      cnt = 0;
    }
  }
  if (cnt > ans.first) {
    ans.first = cnt;
    ans.second = 1;
  } else if (cnt == ans.first) {
    ++ans.second;
  }
  if (!ans.first) ans.second = 1;
  cout << ans.first << ' ' << ans.second;
  return 0;
}
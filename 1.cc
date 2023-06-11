/**
 * @file 1.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-07
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
stack<char> st;
string s;
// ()[]{}
bool judge() {
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
      continue;
    } else if (!st.empty()) {
      if (c == ')') {
        if (st.top() == '(')
          st.pop();
        else
          return false;
      } else if (c == ']') {
        if (st.top() == '[')
          st.pop();
        else
          return false;
      } else if (c == '}') {
        if (st.top() == '{')
          st.pop();
        else
          return false;
      }
    }
  }
  if (st.empty()) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  file(data);
  cin >> s;
  cout << judge();
  return 0;
}
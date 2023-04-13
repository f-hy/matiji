/**
 * @file 1.cc
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
const int maxn = 101;
int n, op, val;
stack<int> st;
multiset<int> ms;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  while (n--) {
    cin >> op;
    switch (op) {
      case 1: {
        cin >> val;
        st.push(val);
        ms.emplace(val);
        break;
      }
      case 2: {
        val = st.top();
        st.pop();
        ms.erase(val);
        break;
      }
      case 3: {
        cout << st.top() << endl;
        break;
      }
      case 4: {
        cout << *ms.begin() << endl;
        break;
      }
    }
  }
  return 0;
}
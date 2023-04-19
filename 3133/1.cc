/**
 * @file 1.cc
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
const int maxn = 1e5 + 1;
ll n, num;
char op;
priority_queue<ll, vector<ll>, greater<ll>> large;
priority_queue<ll> small;
int main() {
  // ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  while (n--) {
    cin >> op;
    switch (op) {
      case '+': {
        cin >> num;
        large.push(num);
        if (large.size() == 1) break;
        if (large.size() == small.size() + 1) {
          if (large.top() < small.top()) {
            large.push(small.top());
            small.pop();
            small.push(large.top());
            large.pop();
          }
        } else {
          small.push(large.top());
          large.pop();
        }
        break;
      }
      case '?': {
        if (large.size() > small.size()) {
          cout << large.top() << endl;
        } else {
          cout << (float)(large.top() + small.top()) / 2 << endl;
        }
        break;
      }
    }
  }
  return 0;
}
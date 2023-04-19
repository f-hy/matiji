/**
 * @file 3.cc
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
int n, steps;
void step() {
  while (n) {
    if (n & 1)
      --n;
    else
      n >>= 1;
    ++steps;
  }
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  step();
  cout << steps;
  return 0;
}
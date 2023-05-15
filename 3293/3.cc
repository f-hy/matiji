/**
 * @file 3.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-14
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
int a, m, cnt;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  a = read();
  m = read();
  while (a % m != 0) {
    a = a + a % m;
    cnt++;
    if (cnt > 100000) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
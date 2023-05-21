/**
 * @file 4.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-21
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

int main() {
  ios::sync_with_stdio(false);
  // file(data);
  int n, p;
  scanf("%d%d", &n, &p);
  int *a = (int *)malloc(sizeof(int) * n);
  int *b = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i > 0)
      b[i] = a[i] - a[i - 1];
    else
      b[i] = a[i];
  }
  for (int i = 0; i < p; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    b[x - 1] += z;
    if (y < n) b[y] -= z;
  }
  int min = b[0];
  for (int i = 1; i < n; i++) {
    b[i] += b[i - 1];
    if (b[i] < min) min = b[i];
  }
  printf("%d", min);
  return 0;
}
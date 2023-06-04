/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-04
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
int n, k, p, m, x;
struct NODE {
  int l, r;
  bool flag;
} stu[maxn];
int head, tail, curr;
void insert(int curr, int num) {
  stu[num].r = stu[curr].r;
  stu[num].l = curr;
  if (stu[curr].r) stu[stu[curr].r].l = num;
  stu[curr].r = num;
  if (!stu[num].r) tail = num;
}
void del(int curr) {
  stu[stu[curr].l].r = stu[curr].r;
  if (stu[curr].r) stu[stu[curr].r].l = stu[curr].l;
  if (!stu[curr].r) tail = stu[curr].l;
  stu[curr].flag = true;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n;
  insert(head, 1);
  rep(i, 2, n) {
    cin >> k >> p;
    if (!p)
      insert(stu[k].l, i);
    else
      insert(k, i);
  }
  cin >> m;
  while (m--) {
    cin >> x;
    if (!stu[x].flag) del(x);
  }
  curr = stu[head].r;
  while (curr) {
    cout << curr << ' ';
    curr = stu[curr].r;
  }
  return 0;
}
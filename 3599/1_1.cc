/**
 * @file 1_1.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-06-03
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
const int maxn = 2e6 + 7;
struct NODE {
  ll nex;
  pll ce;  // coef expn
} node[maxn];
int n, m, head, tail, cur;
pll cea[maxn], ceb[maxn];
void insert(int curr, pll ce) {
  node[++cur].ce = ce;
  node[cur].nex = node[curr].nex;
  node[curr].nex = cur;
  if (!node[cur].nex) tail = cur;
}
int main() {
  //   ios::sync_with_stdio(false);
  // file(data);
  //   cin >> n >> m;
  scanf("%d%d", &n, &m);
  rep(i, 0, n - 1)
      scanf("%lld%lld", &cea[i].first,
            &cea[i].second);  // cin >> cea[i].first >> cea[i].second;
  rep(i, 0, m - 1)
      scanf("%lld%lld", &ceb[i].first,
            &ceb[i].second);  // cin >> ceb[i].first >> ceb[i].second;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (cea[i].second == ceb[j].second) {
      insert(tail, {cea[i].first + ceb[j].first, cea[i].second});
      ++i, ++j;
    } else if (cea[i].second < ceb[j].second)
      insert(tail, cea[i++]);
    else
      insert(tail, ceb[j++]);
  }
  while (i < n) insert(tail, cea[i]), ++i;
  while (j < m) insert(tail, ceb[j]), ++j;
  for (i = node[head].nex; i; i = node[i].nex)
    if (node[i].ce.first)
      printf("%lld %lld\n", node[i].ce.first, node[i].ce.second);
  //   cout << node[i].ce.first << ' ' << node[i].ce.second << endl;
  return 0;
}
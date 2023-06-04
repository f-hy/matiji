/**
 * @file 5.cc
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
struct NODE {
  ll l, r, val, lz;
} tree[maxn << 2];
ll a[maxn];
void build(ll p, ll l, ll r) {
  tree[p].l = l, tree[p].r = r;
  if (l == r) {
    tree[p].val = a[l];
    return;
  }
  ll mid = l + ((r - l) >> 1);
  build(p << 1, l, mid);
  build((p << 1) + 1, mid + 1, r);
  tree[p].val = tree[p << 1].val + tree[(p << 1) + 1].val;
}
void lazy(ll p, ll v) {
  ll s = tree[p].l, t = tree[p].r;
  tree[p].val += (t - s + 1) * v, tree[p].lz += v;
}
void pushdown(ll p) {
  lazy(p << 1, tree[p].lz), lazy((p << 1) + 1, tree[p].lz);
  tree[p].lz = 0;
}
void update(ll l, ll r, ll c, ll p) {
  ll s = tree[p].l, t = tree[p].r;
  if (l <= s && t <= r) return lazy(p, c);
  if (tree[p].lz && s != t) pushdown(p);
  ll mid = s + ((t - s) >> 1);
  if (l <= mid) update(l, r, c, p << 1);
  if (r > mid) update(l, r, c, (p << 1) + 1);
  tree[p].val = tree[p << 1].val + tree[(p << 1) + 1].val;
}
ll query(ll l, ll r, ll p) {
  ll s = tree[p].l, t = tree[p].r;
  if (l <= s && t <= r) return tree[p].val;
  if (tree[p].lz) pushdown(p);
  ll mid = s + ((t - s) >> 1), sum = 0;
  if (l <= mid) sum = query(l, r, p << 1);
  if (r > mid) sum += query(l, r, (p << 1) + 1);
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  int n, m;
  ll op, x, y, k;
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  build(1, 1, n);
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      update(x, y, k, 1);
    } else {
      cin >> x >> y;
      cout << query(x, y, 1) << endl;
    }
  }
  return 0;
}
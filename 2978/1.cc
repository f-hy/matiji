/**
 * @file 1.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-05
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
const int maxn = 1e3 + 1;
int n, x, a, b[maxn];
set<int> lefts, rights;  //-,+
bool is_recorded(int num = a) {
  auto pl = lefts.lower_bound(-num);
  auto pr = rights.lower_bound(num);
  if (pl == lefts.end()) {
    if (pr == rights.end()) return false;
    if (num > (*pr - x)) return true;
    return false;
  } else {
    if (pr != rights.end()) {
      if (num > (*pr - x)) return true;
    }
    if ((-num) > (*pl - x)) return true;
    return false;
  }
}
void getnewa() {
  a = 1;
  while (is_recorded(a)) {
    auto temp = rights.lower_bound(a);
    if (temp == rights.end())
      a = *rights.rbegin();
    else
      a = *temp;
    a += x;
  }
}
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> x;
  rep(i, 1, n) {
    cin >> a;
    if (is_recorded(a)) getnewa();
    b[i] = a;
    lefts.insert(-a);
    rights.insert(a);
  }
  rep(i, 1, n) cout << b[i] << ' ';
  return 0;
}
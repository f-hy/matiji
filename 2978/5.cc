/**
 * @file 5.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-04-06
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
char de[123], c;
string s;
int cnt[123];
int delta[123];  // 97-122
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> s;
  rep(i, 97, 122) {
    // scanf("%c", &c);
    de[i] = s[i - 97];
  }
  cin >> s;
  int* ansi = new int[s.size()];
  rep(i, 0, s.size() - 1)++ cnt[s[i]];
  rep(i, 97, 122) { rep(j, 1, cnt[de[i]]) cout << char(de[i]); }
  return 0;
}
/**
 * @file 4.cc
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
const int maxn = 1e4 + 1;
int n, k, a[maxn], b[maxn];
struct Node {
  int sum, b;
  Node(int sum, int b) : sum(sum), b(b) {}
  bool operator<(const Node &b) const { return sum > b.sum; }
};
priority_queue<Node> minList;
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  cin >> n >> k;
  rep(i, 0, n - 1) { cin >> a[i]; }
  rep(i, 0, n - 1) { cin >> b[i]; }
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    minList.push(Node(a[i] + b[0], 0));
  }
  while (k--) {
    Node node = minList.top();
    minList.pop();
    cout << node.sum << " ";
    int tempB = node.b;
    if (tempB + 1 < n) {
      minList.push(Node(node.sum - b[tempB] + b[tempB + 1], tempB + 1));
    }
  }
  return 0;
}
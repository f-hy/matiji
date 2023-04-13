#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int rec[400][400], n, m, k;
vector<int> a;
vector<int> u, v;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &rec[i][j]);
    }
  }
  for (int i = 1; i <= m; i++) u.push_back(rec[1][i]);
  for (int i = 2; i <= n; i++) {
    sort(rec[i] + 1, rec[i] + 1 + m);
    for (int j = 1; j <= k; j++) v.push_back(rec[i][j]);
    for (int x : u) {
      for (int y : v) {
        a.push_back(x + y);
      }
    }
    sort(a.begin(), a.end());
    while (u.size() != 0) u.pop_back();
    while (v.size() != 0) v.pop_back();
    for (int i = 0; i < k; i++) u.push_back(a[i]);
    while (a.size() != 0) a.pop_back();
  }
  for (int i = 0; i < k; i++) {
    printf("%d ", u[i]);
  }
  return 0;
}
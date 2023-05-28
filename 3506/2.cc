/**
 * @file 2.cc
 * @author Friendy (friend0@qq.com)
 * @date 2023-05-28
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
struct node {
  int no;
  struct node *next;
};
int main() {
  ios::sync_with_stdio(false);
  // file(data);
  int n, k, m, sum = 0;
  scanf("%d %d", &n, &m);
  k = 1;
  struct node *head, *p, *q;
  head = (struct node *)malloc(sizeof(struct node));
  head->no = 1;
  head->next = head;
  for (int i = n; i > 1; i--) {
    p = (struct node *)malloc(sizeof(struct node));
    p->no = i;
    p->next = head->next;
    head->next = p;
  }
  for (int i = 0; i < n - 1; i++) p = p->next;
  for (int i = 0; i < k - 1; i++) p = p->next;
  int flag = 0;
  while (n != 1) {
    for (int i = 0; i < m - 1; i++) p = p->next;
    if (flag == 1) p = p->next;
    flag = 1;
    for (int j = 0; j < n - 1; j++) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    n--;
  }
  printf("%d\n", p->no);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int st1[30], st2[30];

int main() {
  while (cin >> s1 >> s2) {
    memset(st1, 0, sizeof(st1));
    memset(st2, 0, sizeof(st2));
    if (s1.length() != s2.length()) {
      cout << "NO" << endl;
      continue;
    }
    for (int i = 0; i < s1.length(); i++) {
      st1[s1[i] - 'A']++;
      st2[s2[i] - 'A']++;
    }
    sort(st1, st1 + 26);
    sort(st2, st2 + 26);
    bool flag = true;
    for (int i = 0; i < 26; i++) {
      if (st1[i] != st2[i]) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
/**
 * @file 1.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-03-29
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2023
 * 17/20
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define file(x)                                                                \
    freopen(#x ".in", "r", stdin);                                             \
    freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define dwn(i, s, t) for (int i = s; i >= t; i--)
#define ite(it, s, e) for (auto it = s; it != e; ++it)
string email;
int l;
bool not_legal;
bool check(char ch) {
    if ((ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' ||
         ch >= '0' && ch <= '9' || ch == '_'))
        return true;
    else
        return false;
}
int is_username_legal(string s) {
    for (int i = 0; i < s.length() && i <= 16; ++i) {
        if (s[i] == '@' && i > 0 && i + 1 < s.length()) {
            return i + 1;
        }
        if (!check(s[i]))
            return 0;
    }
    return 0;
}
int is_hostname_legal(string s) {
    if (s[0] == '.' || s.length() > 32)
        return 0;
    int cnt = 0;
    int i = 0;
    for (; i < s.length() && i <= 32; ++i) {
        if (s[i] != '.') {
            if (!check(s[i]))
                return 0;
            else if (s[i] == '/') {
                if (!cnt || i + 1 >= s.length())
                    return 0;
                else
                    return i + 1;
            } else
                ++cnt;
        } else {
            if (cnt > 16 || cnt == 0)
                return 0;
            cnt = 0;
        }
    }
    if (cnt > 16 || i > 32 || s[s.length() - 1] == '.')
        return 0;
    return -1;
}
bool is_resource_legal(string s) {
    rep(i, 0, s.length() - 1) if (!check(s[i])) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    file(data);
    cin >> email;
    l = is_username_legal(email);
    if (!l) {
        cout << "NO" << endl;
        return 0;
    }
    l = is_hostname_legal(email.substr(l));
    if (l == -1) {
        cout << "YES" << endl;
        return 0;
    } else if (!l) {
        cout << "NO" << endl;
        return 0;
    }
    if (is_resource_legal(email.substr(l))) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
    return 0;
}
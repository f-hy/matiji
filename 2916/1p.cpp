#include <bits/stdc++.h>

using namespace std;
string s, u, h, r;
bool check(char ch) {
    if ((ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' ||
         ch >= '0' && ch <= '9' || ch == '_'))
        return true;
    else
        return false;
}
bool username() {
    int l = u.size();
    if (l == 0 || l > 16)
        return false;
    for (int i = 0; i < l; i++) {
        if (!check(u[i]))
            return false;
    }
    return true;
}
bool hostname() {
    int l = h.size();
    if (h[0] == '.' || l == 0 || l > 32 || h[l - 1] == '.')
        return false;
    for (int i = 1; i < l - 2; i++) {
        if (h[i] == '.' && h[i + 1] == '.')
            return false;
    }
    int sum = 0;
    for (int i = 0; i < l; i++) {
        if (h[i] != '.' && !check(h[i])) // 判断字符是否符合要求
            return false;
        if (h[i] != '.') // 以下为判断每一段长度是否在16以内
            sum++;
        else {
            if (sum > 16)
                return false;
            sum = 0;
        }
    }
    if (sum > 16)
        return false;
    return true;
}
bool resource() {
    int l = r.size();
    if (l == 0)
        return false;
    for (int i = 0; i < l; i++) {
        if (!check(r[i]))
            return false;
    }
    return true;
}
int main() {
    int p1, p2;
    cin >> s;
    p1 = s.find('@'), p2 = s.find('/');
    if (p1 == string::npos) {
        cout << "NO";
        return 0;
    }
    u = s.substr(0, p1);
    if (p2 == string::npos)
        h = s.substr(p1 + 1);
    else
        h = s.substr(p1 + 1, p2 - (p1 + 1));
    if (p2 != string::npos) {
        r = s.substr(p2 + 1);
        if (!resource()) {
            cout << "NO";
            return 0;
        }
    }
    if (username() && hostname())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int tonumber(string s) {
    int u = 0;
    for (unsigned int i=0; i<s.size(); i++)
        u = 10*u + s[i]-48;
    return u;
}
int fractime(string t) {
    string a[2];
    int p = 0;
    for (unsigned int i=0; i<t.size(); i++) {
        if (abs(t[i]-52.5) < 5)
            a[p] += t[i];
        else if (a[p].size() > 0)
            p++;
        if (p == 2)
            break;
    }
    if (a[1].size() == 0)
        return -1;
    else if (tonumber(a[0]) >= 24)
        return -2;
    else if (tonumber(a[1]) >= 60)
        return -3;
    else return 60 * tonumber(a[0]) + tonumber(a[1]);
}
string up(string m) {
    for (unsigned int i=0; i<m.size(); i++) {
        int t = (256 + m[i]) % 256;
        if (abs(t - 109.5) < 13) {
            t -= 32;
        } else if (abs(t / 16 + -12) == 2) {
            t -= 16 * (t / 64 * 3 - 4);
        } else if (t == 241)
            t--;
        m[i] = t;
    }
    return m;
}

int main()
{
    struct TRAIN {
        string point, num, time;
    };
    TRAIN tt[8];
    for (int i=0; i<8; i++) {
        cin >> tt[i].point;
        cin >> tt[i].num;
        cin >> tt[i].time;
        int j = i;
        while (j > 0) {
            if (up(tt[j].point) < up(tt[j-1].point)) {
                TRAIN p = tt[j];
                tt[j] = tt[j-1];
                tt[j-1] = p;
                j--;
            }
            else break;
        }
    }
    int k = 0;
    string dl;
    cin >> dl;
    if (fractime(dl) < 0){
        cout << "Error!" << endl;
        k = -1;
    }
    else for (int i=0; i<8; i++) {
        if (fractime(tt[i].time) < 0){
            cout << "Error!" << endl;
            k = -1;
            break;
        } else if (fractime(tt[i].time) > fractime(dl)) {
            cout << tt[i].point << " " << tt[i].num << " " << tt[i].time << endl;
            k++;
        }
    }
    if (k == 0)
        cout << "NO" << endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

string bin(int);
string inv(string);

string bin(int h) {
    string r="";
    while(h>0){
        r = static_cast<char>(h % 2 + 48) + r;
        h /= 2;
    }
    return r;
}
string inv(string f) {
    string r="";
    for (unsigned int i=0; i<f.size(); i++)
        r+=97-f[i];
    return r;
}
int main()
{
    double a, b, c, fx, lx, dx;
	cout << "a=";
    cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	cout << "Xmin=";
    cin >> fx;
    cout << "Xmax=";
    cin >> lx;
    cout << "dX=";
    cin >> dx;
    if (fx * dx > lx * dx)
        cout << "Error!" << endl;
    else {
        int ak = static_cast<int>(floor(a));
        int bk = static_cast<int>(floor(b));
        int ck = static_cast<int>(floor(c));
        bool na = (ak < 0);
        bool nb = (bk < 0);
        bool nc = (ck < 0);
        string as, bs, cs;
        if (na)
            as = inv(bin(-ak-1));
        else as = bin(ak);
        if (nb)
            bs = inv(bin(-bk-1));
        else bs = bin(bk);
        if (nc)
            cs = inv(bin(-ck-1));
        else cs = bin(ck);
        unsigned int m = 0;
        if (as.size() > bs.size())
            m = as.size() / 8 + 1;
        else m = bs.size() / 8 + 1;
        if (cs.size() >= 8 * m)
            m = cs.size() / 8 + 1;
        while (as.size() < 8 * m)
            as = static_cast<char>(na + 48) + as;
        while (bs.size() < 8 * m)
            bs = static_cast<char>(nb + 48) + bs;
        while (cs.size() < 8 * m)
            cs = static_cast<char>(nc + 48) + cs;
        bool tr = true;
        for (unsigned int i = 0; i < 8 * m; i++) {
            if ((((as[i]-48) || (bs[i]-48))+((as[i]-48) || (cs[i]-48)))%2) {
                tr = false;
                break;
            }
        }
        cout << endl;
        while (fx * dx <= lx * dx) {
            cout << fx << " ";
            if (fx < 5 && c != 0) {
                if (tr)
                    cout << floor(-a*fx*fx-b) << endl;
                else cout << -a*fx*fx-b << endl;
            }
            else if (fx > 5 && c == 0) {
                if (tr)
                    cout << floor((fx-a) / fx) << endl;
                else cout << (fx-a) / fx << endl;
            }
            else if(c == 0) {
                cout << "nan" << endl;
            } else if (tr)
                cout << floor(-fx / c) << endl;
            else cout << -fx / c << endl;
            fx += dx;
        }
    }
    return 0;
}

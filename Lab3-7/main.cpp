#include <fstream>

using namespace std;

int main()
{
    int a[8][8];
    int i, k;
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    for (i=0; i<64; i++)
        fin >> a[i/8][i%8];
    fout << "K={";
    bool j = 0;
    for (k=0; k<8; k++) {
        bool t = 1;
        for (i=0; i<8; i++) {
            if (a[k][i] != a[i][k]) {
                t = 0;
                break;
            }
        }
        if (t) {
            if (j)
                fout << "; ";
            fout << k+1;
            j = 1;
        }
    }
    fout << "}" << endl;
    int sum = 0;
    for (k=0; k<8; k++) {
        j = 0;
        int s = 0;
        for (i=0; i<8; i++) {
            s += a[k][i];
            if (a[k][i] < 0)
                j = 1;
        }
        if (j)
            sum += s;
    }
    fout << "S=" << sum;
    return 0;
}

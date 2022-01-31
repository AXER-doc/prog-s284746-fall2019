#include <iostream>
#include <fstream>

using namespace std;

int* sort(int* a, int n) {
    int i;
    int *b = new int[n];
    bool *u = new bool[n];
    for (i=0; i<n; i++)
        u[i] = 1;
    for (int k=0; k<n; k++) {
        int y = -1;
        float m = 2.5;
        for (i=0; i<n; i++) {
            if (u[i]) {
                if ((2*m == 5) || (m > a[i])) {
                    m = a[i];
                    y = i;
                }
            }
        }
        b[k] = m;
        u[y] = 0;
    }
    return b;
}

int main() {
    ifstream fin("input.txt");
	int i, n, max, imax, k;
	fin >> n;
	int *a = new int[n];
	fin >> a[0];
	max = a[0];
	imax = 0;
	k = (a[0]==0);
	int p = 1;
	for (i=1; i<n; i++) {
		fin >> a[i];
		if (a[i] >= max) {
			max = a[i];
			imax = i;
		}
		if (a[i]==0)
			k++;
		else if (k == 1)
			p *= a[i];
	}
	cout << "i=" << imax + 1 << endl << "p=" << p << endl;
	for (i=1; i<=n; i++) {
		int j=2*i-2;
		cout << a[(j+j/n*((n+1)%2))%n];
		if (i == n)
            cout << endl;
        else cout << " ";
	}
	a = sort(a, n);
	for (i=0; i<n; i++) {
        if (i > 0)
            cout << " ";
        cout << a[i];
	}
	return 0;
}

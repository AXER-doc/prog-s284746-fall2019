#include <iostream>

using namespace std;

struct node {
    int value;
    struct node *next;
};
void CONSTRUCT(node **b, node **e, int el, int &l) {
    node *r = new (node);
    (*r).value = el;
    (*r).next = NULL;
    *b = r;
    *e = r;
    l = 1;
}
void push(node **e, int x, int &l) {
    node *r = new (node);
    (*r).value = x;
    (*r).next = NULL;
    (**e).next = r;
    *e = r;
    l++;
}
void shift(node **b, int &l) {
	node *r;
	r = *b;
	cout << "Removed element " << (*r).value << endl;
	r = (*r).next;
	*b = r;
	l--;
}
void out(node **b, int &l) {
    node *r;
	r = *b;
	cout << "Queue";
	while(l > 0) {
	    cout << " " << (*r).value;
        r = (*r).next;
        *b = r;
        l--;
	}
	cout << endl;
}
void off(node **b, int &l) {
    node *r;
	r = *b;
	while(l > 0) {
        r = (*r).next;
        *b = r;
        l--;
	}
}
int main()
{
    node *b, *e;
    int l = 0;
    int n;
    cout << "EMPTY" << endl;
    cout << "0 Stop" << endl;
    cout << "1 Create queue" << endl;
    cin >> n;
    while (n != 0) {
        if (l == 0) {
            if (n == 1) {
                int p;
                cout << "First element: ";
                cin >> p;
                CONSTRUCT(&b, &e, p, l);
                cout << "Created queue with element " << (*e).value << endl;
            } else {
                cout << "Error!" << endl;
            }
        } else {
            switch (n) {
            case 1:
                int p;
                cout << "Enter value: ";
                cin >> p;
                push(&e, p, l);
                cout << "New element " << (*e).value << endl;
                break;
            case 2:
                shift(&b, l);
                break;
            case 3:
                out(&b, l);
                cout << "Successfully cleared" << endl;
                break;
            default:
                cout << "Error!" << endl;
            }
        }
        if (l == 0) {
            cout << "EMPTY" << endl;
            cout << "0 Stop" << endl;
            cout << "1 Create queue" << endl;
        } else {
            cout << "0 Stop" << endl;
            cout << "1 Add" << endl;
            cout << "2 Delete" << endl;
            cout << "3 Read & Clear" << endl;
        }
        cin >> n;
    }
    off(&b, l);
    return 0;
}

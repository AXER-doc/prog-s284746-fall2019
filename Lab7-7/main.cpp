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
    (*r).next = *e;
    (**e).next = r;
    *e = r;
    l++;
}
void pop(node **e, int &l) {
    node *r;
	r = *e;
	cout << "Removed element " << (*r).value << endl;
	r = (*r).next;
	*e = r;
	l--;
}
void shift(node **b, int &l) {
	node *r;
	r = *b;
	cout << "Removed element " << (*r).value << endl;
	r = (*r).next;
	*b = r;
	l--;
}
void unshift(node **b, int x, int &l) {
    node *r = new (node);
    (*r).value = x;
    (*r).next = *b;
    (**b).next = r;
    *b = r;
    l++;
}
int main()
{
    node *b, *e;
    int l = 0;
    int n;
    cout << "EMPTY" << endl;
    cout << "0 Stop" << endl;
    cout << "1 Create deque" << endl;
    cin >> n;
    while (n != 0) {
        if (l == 0) {
            if (n == 1) {
                int p;
                cout << "First element: ";
                cin >> p;
                CONSTRUCT(&b, &e, p, l);
                cout << "Created deque with element " << (*e).value << endl;
            } else {
                cout << "Error!" << endl;
            }
        } else {
            switch (n) {
            case 1:
                int p;
                cout << "Enter value: ";
                cin >> p;
                unshift(&b, p, l);
                cout << "New element " << (*b).value << endl;
                break;
            case 2:
                cout << "Enter value: ";
                cin >> p;
                push(&e, p, l);
                cout << "New element " << (*e).value << endl;
                break;
            case 3:
                shift(&b, l);
                break;
            case 4:
                pop(&e, l);
                break;
            default:
                cout << "Error!" << endl;
            }
        }
        if (l == 0) {
            cout << "EMPTY" << endl;
            cout << "0 Stop" << endl;
            cout << "1 Create deque" << endl;
        } else {
            cout << "Deque length: " << l << endl;
            cout << "0 Stop" << endl;
            cout << "1 Add to beginning" << endl;
            cout << "2 Add to end" << endl;
            cout << "3 Delete from beginning" << endl;
            cout << "4 Delete from end" << endl;
        }
        cin >> n;
    }
    while (l > 0)
        pop(&e, l);
    return 0;
}

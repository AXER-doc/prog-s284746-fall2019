#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
};
void push(node **k, int x, int &l) {
    node *p = new (node);
    (*p).value = x;
    (*p).next = *k;
    *k = p;
    l++;
}
int pop(node **k, int &l) {
    int drop = (*k)->value;
    *k = (**k).next;
    l--;
    return drop;
}
int main()
{
    int n;
    string c;
    cout << "arrive [number]" << endl;
    cout << "leave [number]" << endl;
    cout << "stop" << endl;
    cin >> c;
    if (c == "arrive" || c == "leave")
        cin >> n;
    node *m = NULL;
    int l = 0;
    while (c != "stop") {
        if (c == "arrive") {
            push(&m, n, l);
            cout << "Car " << (*m).value << " has arrived" << endl;
        } else if (c == "leave") {
            if (l == 0)
                cout << "Error!" << endl;
            else {
                node *r = NULL;
                int i = 0;
                while (l > 0) {
                    if ((*m).value == n)
                        break;
                    else {
                        cout << "Car " << (*m).value << " was removed" << endl;
                        push(&r, pop(&m, l), i);
                    }
                }
                if (l == 0)
                    cout << "Error!" << endl;
                else cout << "Car " << pop(&m, l) << " has left" << endl;
                while (i > 0) {
                    push(&m, pop(&r, i), l);
                    cout << "Car " << (*m).value << " was returned" << endl;
                }
            }
        } else cout << "Error!" << endl;
        cout << "arrive [number]" << endl;
        cout << "leave [number]" << endl;
        cout << "stop" << endl;
        cin >> c;
        if (c == "arrive" || c == "leave")
            cin >> n;
    }
    while (l > 0) {
        pop(&m, l);
    }
    return 0;
}

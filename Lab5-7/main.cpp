#include <iostream>

using namespace std;

struct node{
    int value;
    struct node *next;
};
void push(node **stk, int x, int &l){
    node *t = new (node);
    (*t).value = x;
    (*t).next = *stk;
    *stk = t;
    l++;
}
int pop(node **stk, int &l){
    int drop = (*stk)->value;
    *stk = (**stk).next;
    l--;
    return drop;
}
int main()
{
    node *stk = NULL;
    int l = 0;
    int n;
    cout << "0 Stop" << endl;
    cout << "1 Read" << endl;
    cout << "2 Add" << endl;
    cout << "3 Delete" << endl;
    cout << "4 Clear" << endl;
    cin >> n;
    while (n != 0) {
        switch (n){
        case 1:
            if (l == 0)
                cout << "Error!" << endl;
            else {
                cout << "Last element: " << stk->value << endl;
                cout << "Stack length: " << l << endl;
            }
            break;
        case 2:
            int k;
            cout << "Enter value: ";
            cin >> k;
            push(&stk, k, l);
            cout << "New element: " << stk->value << endl;
            cout << "Stack length: " << l << endl;
            break;
        case 3:
            if (l == 0)
                cout << "Error!" << endl;
            else {
                cout << "Deleted element " << pop(&stk, l) << endl;
                cout << "Stack length: " << l << endl;
            }
            break;
        case 4:
            while (l > 0)
                pop(&stk, l);
            cout << "Successfully cleared" << endl;
            break;
        default:
            cout << "Error!" << endl;
        }
        cout << "0 Stop" << endl;
        cout << "1 Read" << endl;
        cout << "2 Add" << endl;
        cout << "3 Delete" << endl;
        cout << "4 Clear" << endl;
        cin >> n;
    }
    while (l > 0)
        pop(&stk, l);
    return 0;
}

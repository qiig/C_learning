#include "cir_singlyLinkList.h"

int main () {
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    cir_singlyLinkList<int> L{r, 5};
    cout << "Current Sequential List is: ";
    L.PrintList();
    try {
        L.Insert(1, 8);
        cout << "After Inserting SeqList is: ";
        L.PrintList();
    } catch (const char *str) {cout << str << endl;}
    cout << "Current Length of SeqList is: " << L.getLen() << endl;
    cout << "Input: val: ";
    cin >> x;
    i = L.getPos(x);
    if (i == 0) cout << "Failed Finding ... " << endl;
    else cout << x << "'s position is " << i << endl;
    try {
        cout << "Input: pos: ";
        cin >> i;
        cout << i << "'s value is: " << L.getVal(i) << endl;
    } catch (const char *str) {cout << str << endl;}
    try {
        cout << "Input: pos which is supposed to be Deleted: ";
        cin >> i;
        x = L.Delete(i);
        cout << x << " has been deleted. " << endl;
        cout << "Current SeqList is: ";
        L.PrintList();
    } catch (const char *str) {cout << str << endl;}
    return 0;
}





#if 0
// main

int main () {
    int n, ar[101] = {0};
    while (cin >> n && n > 0 && n < 101)
    {
        for (int j = 0; j < n; j++) {
            cin >> ar[j];
        }
        LinkList<int> A{ar, n};
        cout << "Current LinkList is: ";
        A.PrintList();
        int i, x;
        cout << "Input inserting index and value: ";
        cin >> i >> x;
        try {
            A.Insert(i, x);
            cout << "After Insert: ";
            A.PrintList();
        } catch (char *str) {
            cout << str << endl;
        }
        cout << "Current Length is: " << A.Length() << endl;
        
    }
#if 0    
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    LinkList<int> L{r, 5};
    cout << "current LintList is: ";
    L.PrintList ();
    try {
        L.Insert (2, 8);
        cout << "after insert: ";
        L.PrintList ();
    } catch (char *str) {
        cout << str << endl;
    } 
    cout << "current length is: " << L.Length () << endl;
    cout << "input x: ";
    cin >> x;
    i = L.Locate (x);
    if (i > 0) {
        cout << x << "'s location is: " << i << endl;
    } else {
        cout << "no " << x << "in LinkList." << endl;
    }
    try {
        cout << "delete element: ";
        cin >> i;
        x = L.Delete (i);
        cout << x << " is deleted." << ", and current LinkList is: " ;
        L.PrintList ();
    } catch (char *str) {
        cout << str << endl;
    }
#endif
    return 0;
}
#endif
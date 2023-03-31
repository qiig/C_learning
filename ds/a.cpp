#include "seqList.h"

int main () {
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    SeqList<int> L{r, 5};
    cout << "Current Sequential List is: ";
    L.PrintList();
    try {
        L.Insert(2, 8);
        cout << "After Inserting SeqList is: ";
        L.PrintList();
    } catch (char *str) {cout << str << endl;}
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
    } catch (char *str) {cout << str << endl;}
    try {
        cout << "Input: pos which is supposed to be Deleted: ";
        cin >> i;
        x = L.Delete(i);
        cout << x << "has been deleted. " << endl;
        cout << "Current SeqList is: ";
        L.PrintList();
    } catch (char *str) {cout << str << endl;}
    return 0;
}
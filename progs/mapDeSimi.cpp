#include<iostream>
#include<iterator>
#include<map>

using namespace std;

int main() {
    int n;
    while (cin >> n)
    {
        map<int, int> t;
        map<int, int>::iterator it;
        map<int, int>::iterator itEnd;
        int k, v;
        for (int i = 0; i < n; i++)
        {
            bool op = true;
            cin >> k;
            if (i == 0)
            {
                cin >> t[k];
            } else {
                it = t.begin();
                itEnd = t.end();
                while (it != itEnd)
                {
                    if(k == it->first){
                        cin >> v;
                        t[k] = v + it->second;
                        op = false;
                        break;
                    } else {
                        it++;
                    }
                }
                if (op)
                {
                    cin >> t[k];
                }
                   
            } 
        }
        it = t.begin();
        itEnd = t.end();
        while (it != itEnd)
        {
            cout << it->first <<" "<< it->second << endl;
            it++;
        }
        
    t.clear();  
    }
    return 0;
}
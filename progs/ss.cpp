#include<iostream>
#include<queue>
using namespace std;

typedef struct stu1
{
    string na;
    int gr;
    bool operator<(const stu1 &a) const {
        return a.gr < gr;
    }
} STU1;

typedef struct stu0
{
    string na;
    int gr;
    bool operator<(const stu0 &a) const {
        return a.gr > gr;
    }
} STU0;

int main() {
    string s;
    int n, flag, d;
    while (cin >> n >> flag)
    {
        if (flag == 1) {
            STU1 st;
            priority_queue<STU1> ss;
            while (n)
            {
                cin >> s >> d;
                st.na = s;
                st.gr = d;
                ss.push(st);
                n--;
            }
            while (!ss.empty())
            {
                cout << ss.top().na << " " << ss.top().gr << endl;
                ss.pop();
            }
        } else if (flag == 0) {
            STU0 st;
            priority_queue<STU0> ss;
            while (n)
            {
                cin >> s >> d;
                st.na = s;
                st.gr = d;
                ss.push(st);
                n--;
            }
            while (!ss.empty())
            {
                cout << ss.top().na << " " << ss.top().gr << endl;
                ss.pop();
            }
        }
    }
    return 0;
}

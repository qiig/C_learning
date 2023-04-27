#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        string ss = "", ms = "";
        vector<int> d; int dd = 0, sum = 0;
        for(int i = 1; i < s.length(); i++)
        {
            dd = s[i-1] - s[i];
            d.push_back(dd);
        }
        for(int i = 0; i < d.size(); i++)
        {
            sum = 0;
            if(d[i] == 1 || d[i] == -1 || d[i] == 0)
            {
                sum += d[i];
                ss += s[i];
                int j = i+1;
                if(sum == 0)
                {
                    while(j < d.size() && sum == 0 && d[j] == 0)
                    {
                        sum += d[j]; ss += s[j]; j++;
                    }
                    ss += s[j];
                    if(ss.length() > ms.length()) ms = ss; 
                    ss = "";
                } else {
                    while(sum != 0 && j < d.size())
                    {
                        if(d[j] == 1 || d[j] == -1 || d[j] == 0)
                        {
                            sum += d[j]; ss += s[j]; j++;
                        } else {
                            break;
                        }
                    }
                    if(sum == 0)
                    {
                        ss += s[j];
                        if(ss.length() > ms.length()) ms = ss; 
                        ss = "";
                    } else ss = s[i];
                }
            } else {
                ss = s[i];
            }
            if(ss.length() > ms.length()) ms = ss; 
            ss = "";
        }
        d.clear();
        return ms;
    }
};

int main()
{
    Solution sol;
    string s;
    while(cin >> s){
        cout << sol.longestPalindrome(s) << endl;
    }
    return 0;
}
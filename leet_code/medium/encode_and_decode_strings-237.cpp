#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            s += to_string(strs[i].size()) + "#" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            
            int length = stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            ans.push_back(s.substr(i, length));

            i += length;
        }
        
        return ans;
    }
};

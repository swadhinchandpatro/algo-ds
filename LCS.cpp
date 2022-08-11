#include <bits/stdc++.h>
using namespace std;

string getMax(string s1, string s2) {
    if(s1.length() > s2.length()) {
        return s1;
    }
    return s2;
}

string getLCS(string s1, string s2) {
    vector<vector<string>> mem;
    if(s1 == "" || s2 == "") return "";
    for(int i=0;i<=s1.size();i++) {
        vector<string> v(s2.size() + 1, "");
        mem.push_back(v);
    }
    
    // for(int i=1;i<=s1.size();i++) {
    //     for(int j=1;j<=s2.size();j++) {
    //         cout<<mem[i][j]<<" ";
    //     }
    // }
    for(int i=1;i<=s1.size();i++) {
        for(int j=1;j<=s2.size();j++) {
            if(s1[i-1] == s2[j-1]) {
                mem[i][j] = mem[i-1][j-1] + s1[i-1];
            } else {
                mem[i][j] = getMax(mem[i-1][j], mem[i][j-1]);
            }
        }
        cout<<endl;
    }
    
    return mem[s1.size()][s2.size()];
}
int main(){
    string s1="AGGTAB";
    string s2="GXTXAYB";
    
    cout<<getLCS(s1,s2);
    // 10 14 16 6 4 18 20 8
    // int a = -768578 % 3;
    // cout<<a;
    return 0;
}
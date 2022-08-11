#include <bits/stdc++.h>
using namespace std;

bool ifFeasible(int k, int e, int a, int b) {
    int x = e-k;
    return x % __gcd(a,b) == 0;
}

void printPath(int k, int e, int a, int b) {
    if(!ifFeasible(k,e,a,b)) {
        return;
    }
    
    queue<pair<int,int>> q;
    q.push({k,0});
    unordered_map<int,bool> visited;
    
    while(!q.empty()) {
        int start = q.front().first;
        int step = q.front().second;
        cout<<start<<" "<<step<<endl;
        if(start == e) break;
        
        if(!visited[start+a]) {
            q.push({ start+a, step+1 });
        }
        if(!visited[start+b]) {
            q.push({ start+b, step+1 });
        }
        if(!visited[start-a]) {
            q.push({ start-a, step+1 });
        }
        if(!visited[start-b]) {
            q.push({ start-b, step+1 });
        }
        q.pop();
    }
    
    int start;
}

int main(){
    printPath(10,8,4,6);
    // 10 14 16 6 4 18 20 8
    // int a = -768578 % 3;
    // cout<<a;
    return 0;
}
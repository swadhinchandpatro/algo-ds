// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int size, int root) {
    if(root > size) {
        return;
    }
    int left = 2*root;
    int right = 2*root +1;
    
    int max = root;
    if(left <= size && v[left] > v[max]) {
        max = left;
    }
    if(right <= size && v[right] > v[max]) {
        max = right;
    }
    if(max != root) {
        swap(v[root], v[max]);
        heapify(v, size, max);
    }
}

void heap_build(vector<int> &v, int size) {
    //get first parent node
    int i = floor(size/2);
    while(i > 0) {
        heapify(v, size, i);
        i--;
    }
    //heapfiy it and then go back to each parent until root
}

void print_heap(vector<int> &v) {
    for(auto i=v.begin();i != v.end(); i++) {
        cout<< *i << " ";
    }
}

int heap_max(vector<int> v) {
    return v[1];
}

void heap_sort(vector<int> &v, int size) {
    stack<int> s;
    while(size > 0) {
        //get max and push in stack
        s.push(heap_max(v));
        //heapify root
        v[1] = v[size];
        heapify(v, --size , 1);
    }
    int i = 1;
    while(!s.empty()) {
        v[i++] = s.top();
        s.pop();
    }
}
int main() {
    // Write C++ code here
    vector<int> v1 = {93,28,104,1,34,432,91,4,6};
    // int n = sizeof(a)/sizeof(a[0]);
    vector<int> v(v1);
    v.insert(v.begin(),0);
    
    heap_build(v, v1.size());
    print_heap(v);
    cout<<endl;
    heap_sort(v, v1.size());
    print_heap(v);
    return 0;
}
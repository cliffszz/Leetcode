#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
    int n = arr.size();
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i == n - 1) cout << "]";
        else cout << ", ";
    }
    cout << endl;
}
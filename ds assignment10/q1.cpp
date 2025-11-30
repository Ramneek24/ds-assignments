#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(int a[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.count(a[i])) return true;
        s.insert(a[i]);
    }
    return false;
}

int main() {
    int a[] = {1,2,3,1};
    cout << (containsDuplicate(a,4) ? "true" : "false");
}
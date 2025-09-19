#include <iostream>
#include <vector>
using namespace std;


int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i; 
    }
    return -1; 
}


int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1; 
        else
            high = mid - 1; 
    }
    return -1; 
}

int main() {
 
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int target;

    cout << " Enter the number you want to search: ";
    cin >> target;

    // Linear Search
    int index1 = linearSearch(arr, target);
    if (index1 != -1)
        cout << "Linear Search: Found " << target << " at index " << index1 << "\n";
    else
        cout << "Linear Search: " << target << " not found.\n";

    // Binary Search
    int index2 = binarySearch(arr, target);
    if (index2 != -1)
        cout << " Binary Search: Found " << target << " at index " << index2 << "\n";
    else
        cout << " Binary Search: " << target << " not found.\n";

    cout << "\nComplexity:\n";
    cout << "   • Linear Search → O(n)\n";
    cout << "   • Binary Search → O(log n)\n";

    return 0;
}

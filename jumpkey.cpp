#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int jumpSearch(const vector<int>& arr, int key) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<int> queenList(n);
    cout << "Enter the queen list: ";
    for (int i = 0; i < n; ++i) {
        cin >> queenList[i];
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int result = jumpSearch(queenList, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

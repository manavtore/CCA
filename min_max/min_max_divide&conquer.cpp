#include <iostream>
#include <vector>

using namespace std;

void findMinMax(const vector<int>& arr, int low, int high, int& minVal, int& maxVal) {
    if (low == high) {
        // If there is only one element, it is both the minimum and maximum.
        minVal = maxVal = arr[low];
    } else if (high - low == 1) {
        // If there are two elements, compare them to find the minimum and maximum.
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int leftMin, leftMax, rightMin, rightMax;
        findMinMax(arr, low, mid, leftMin, leftMax);
        findMinMax(arr, mid + 1, high, rightMin, rightMax);

        minVal = min(leftMin, rightMin);
        maxVal = max(leftMax, rightMax);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive number of elements." << endl;
        return 1;
    }

    vector<int> numbers(n);

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int minVal, maxVal;
    findMinMax(numbers, 0, n - 1, minVal, maxVal);

    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}


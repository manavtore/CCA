#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    sort(numbers.begin(), numbers.end()); // Sort the array

    int min_val = numbers[0]; // Minimum value is at the beginning
    int max_val = numbers[n - 1]; // Maximum value is at the end

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;

    return 0;
}


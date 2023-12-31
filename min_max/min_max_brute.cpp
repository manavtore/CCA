#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive number of elements." << endl;
        return 1;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (num < min_val) {
            min_val = num;
        }

        if (num > max_val) {
            max_val = num;
        }
    }

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;

    return 0;
}


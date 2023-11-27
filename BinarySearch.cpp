#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& array, int left, int right, int target)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
            return mid;

        if (array[mid] > target)
            return binarySearch(array, left, mid - 1, target);

        return binarySearch(array, mid + 1, right, target);
    }

    return -1;
}

int main()
{
    vector<int> arr;
    int size, target;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " elements in ascending order:\n";
    for (int i = 0; i < size; ++i) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);
    
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;

    return 0;
}

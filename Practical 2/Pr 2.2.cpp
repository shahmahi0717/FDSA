#include <iostream>
using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1; // Target not found

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return recursiveBinarySearch(arr, left, mid - 1, target);
    else
        return recursiveBinarySearch(arr, mid + 1, right, target);
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int bookCodes[n];

    cout << "Enter the sorted book codes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bookCodes[i];
    }

    int target;
    cout << "Enter target book code: ";
    cin >> target;

    // Iterative Binary Search
    int left = 0, right = n - 1;
    int iterativeResult = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (bookCodes[mid] == target)
        {
            iterativeResult = mid;
            break;
        }
        else if (target < bookCodes[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (iterativeResult != -1)
        cout << "\nIterative Binary Search: Found at position " << iterativeResult << endl;
    else
        cout << "\nIterative Binary Search: Book code not found." << endl;

    // Recursive Binary Search
    int recursiveResult = recursiveBinarySearch(bookCodes, 0, n - 1, target);

    if (recursiveResult != -1)
        cout << "Recursive Binary Search: Found at position " << recursiveResult << endl;
    else
        cout << "Recursive Binary Search: Book code not found." << endl;

    return 0;
}

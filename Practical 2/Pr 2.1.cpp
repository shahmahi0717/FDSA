#include <iostream>
using namespace std;

// Recursive Linear Search
int recursiveSearch(string arr[], int size, string target, int index)
{
    if (index == size)
        return -1; // Target not found

    if (arr[index] == target)
        return index; // Target found

    return recursiveSearch(arr, size, target, index + 1);
}

int main()
{
    int n;
    cout << "Enter number of license plates: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target license plate: ";
    cin >> target;

    // Iterative Linear Search
    int iterativeResult = -1;

    for (int i = 0; i < n; i++)
    {
        if (plates[i] == target)
        {
            iterativeResult = i;
            break;
        }
    }

    if (iterativeResult != -1)
        cout << "\nIterative Search: Found at position " << iterativeResult << endl;
    else
        cout << "\nIterative Search: License plate not found." << endl;

    // Recursive Linear Search
    int recursiveResult = recursiveSearch(plates, n, target, 0);

    if (recursiveResult != -1)
        cout << "Recursive Search: Found at position " << recursiveResult << endl;
    else
        cout << "Recursive Search: License plate not found." << endl;

    return 0;
}

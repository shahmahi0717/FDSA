#include <iostream>
using namespace std;
int main() {
    int n;

    cout << "Enter number of colour codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Selection Sort
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex!=i)
        {
            // Swap
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    cout << "Sorted colour codes: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


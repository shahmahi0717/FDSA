#include <iostream>
using namespace std;
int main() {
    int n, h;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter number of hours: ";
    cin >> h;
    int arr[n];
    cout << "Enter the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    h = h % n;
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[(i + h) % n];
    }
    cout << "Final display order:\n";
    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}

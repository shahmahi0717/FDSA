#include <iostream>
using namespace std;
// bubble sort
void bubbleSort(int array[], int size)
{
  // loop to access each array element
  for (int i = 0; i < size - 1; i++)
    {
    // loop to compare array elements
    for (int j = 0; j < size - i - 1; j++)
    {
      // compare two adjacent elements
      if (array[j] > array[j + 1])
      {
        // swapping elements if elements
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}
// print array
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  // find array's length
  int size = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, size);
  cout << "Sorted Array in Ascending Order:\n";
  printArray(data, size);
}

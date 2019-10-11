/*
* Names: Jacob Liu, Taylor Fix, Yuta Nakamura
* Outside sources: Michael Ching (Gave us the idea to use a Finite State Machine)
*                  Correctly finding size of an array
*                      -https://stackoverflow.com/questions/2037736/how-to-find-the-size-of-an-int
* Assumptions:
*   - Expressions do not start with '.'
*   - Expressions do not include '/'
*   - The only variable used in the expression is 'n'
*   - Expressions do not include special characters i.e. '@', '!'
*   - All multiplication between numbers and variables are resolved before being entered i.e. 16 not 4*4 and n^3 not n*n*n
*   - There will be no integers multiplied after the variable
*   - No constant logarithmic expressions entered as coefficients
*/

#include <iostream>

using namespace std;

/*---------- Function Protypes ----------*/
// Sorts the user's array into descending order
void selectionSort(int*, int);
// Finds the subset from the user's array
void findSubset(int target, const int sortedArray[], int subSet[], int size);

/*---------- Main Function ----------*/
int main(){
  int size = 0;
  int subsetSize = 0;
  int target;

  // Getting the size of the sorted array from the user
  cout << "Please enter the array size: " << endl;
  cin  >> size;

  // Creating the array of userdefined size
  int sortedArray[size];
  int subset[size];

  // Filling the array with 0s
  for (int i = 0; i < size; i++){
    sortedArray[i] = 0;
    subset[i] = 0;
  }

  // Asking for the number to put inside of the array
  cout << "Please input the numbers you wish to include in the array: " << endl;
  for (int i = 0; i < size; i++){
    cin  >> sortedArray[i];
  }

  // Asking for the product you are going to look for
  cout << "Please input the number you wish to find the product for: " << endl;
  cin  >> target;

  // Sorts the array into descending order
  selectionSort(sortedArray, size);

  // Finding the subset of the product
  findSubset(target, sortedArray, subset, size);

  // Finding the size of the subset
  for (int i = 0; i < size; i++){
    if (subset[i] != 0){
      subsetSize++;
    }
  }

  // If the subset is empty or size 1
  if (subsetSize == 0 || subsetSize == 1){
    cout << "There are no possible combinations of numbers whose product produces the target number." << endl;
  }
  // If the subset has numbers in it
  else{
    cout << "Your subset is { ";
    for (int i = 0; i < subsetSize; i++){
      if (subset[i] != 0){
        cout << subset[i] << " ";
      }
    }
    cout << "}" << endl;
  }
}

/*---------- Function Definitions ----------*/
// Sort the array into descending order
void selectionSort(int* arr, int arrSize){
    int minInd;
    for(int i = 0; i < arrSize; i++){
        minInd = i;
        for(int j = i; j < arrSize; j++){
            if(arr[minInd] < arr[j]){
                int temp = arr[minInd];
                arr[minInd] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Find the subset of the products
void findSubset(int target, const int sortedArray[], int subSet[], int size){
  // This is the counter for the subset array
  int count = 0;
  int resetTarget = target;

  // For the entire length of the array
  for (int k = 0; k < size; k++)
  {
    target = resetTarget;
    count = 0;

    // For the rest of the length of the array
    for (int i = k; i < size; i++)
    {
      // If the element is greater than 0
      if (sortedArray[i] != 0)
      {
        // If the target is divisible by the element
        if (target % sortedArray[i] == 0)
        {
          // New target is the quotient
          target /= sortedArray[i];
          // Store the number
          subSet[count] = sortedArray[i];
          count ++;

          // Looks to see if the quotient is in the array
          for (int j = i+1; j < size; j++)
          {
            // If it is in the array, store
            if (sortedArray[j] == target)
            {
              subSet[count] = target;
              return;
            }
          }
        }

      }
    }

  }
}

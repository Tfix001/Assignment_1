//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
//Outside sources:
#include <iostream>

using namespace std;

/*
Assuming...
*/

/*Given an array with integers inside. Also given one outside integer. Want to find a subset of integers inside the array when multiplied
*  together will equal the outside integer.

* Find a number in the array that divides the target number wholly.
* Use the quoitent of that to determine what number you need to find next.
* End when the quoitent is equal to 1. 
* If the array does not have a number that divides the target number, then the product does not exist

Examples:
15 = 5 * 3 * 1
18 = 3 * 3 * 2 * 1 OR 6 * 3 * 1
20 = 10 * 2 * 1
DOES NOT WORK (unless 1 is in the Array): 37 = 37 * 1
*/

//Array[size] = {what's inside the array}

void selectionSort(int*, int);

int main(){
  
  selectionSort(userArr, Arrsize); //TODO FIX NAME
  
  return 0;
}

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

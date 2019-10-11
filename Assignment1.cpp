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

Using pseudocode method shown below (Currently)

first target = 37
array = 16 2 1 37
after first findSubset call
target = 37
array = 16 2 0 37
subsetarray = 1
after second findSubset call
target = 37
array = 16 2 0 37
subsetarray = 1 37
Should return the subsetArray? Should return somehow.
--Meaning that the subset gets back to the main function. 
  Either by the output of the function, or since it was a reference in the function?



*  Taylor's Theory: 
*  (Possibly recurrsive program?)
*  Call a function with an array, a target number, and a subsetArray? (Not sure how to get the subset otherwise)
*  --Either check if the array is empty here or in the main function
*    If array at index is 0 -> skip it
*    If we can find a number such that target number % array at index is 0   (% 1 gives 0 as output too)
*      -> newNumber becomes the array at index
*      -> subsetArray gets the newNumber
*      -> If subsetArray product does not equal target number ------ Helper function?
*        -> target number becomes target number / newNumber
*        -> array at index becomes 0
*        -> call the function with the new array, and target number (Should be simpler to check through?)
*      -> Else the product does equal target number and we can return the subsetArray.
*    Else the target number does not have a subset of array ints that will produce it as a product
*  End Call
*/

//If my thinking is correct, we should really only have O(n) here. Since I don't think there should be a nested loop

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

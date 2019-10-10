//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
//Outside sources:
#include <iostream>
#include <vector>

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
after first findSubsetProduct call
target = 37
array = 16 2 0 37
newArrary = 1
after second findSubsetProduct call
target = 1
array = 16 2 0 0
newArray = 1 37
after third findSubsetProduct call
"No possible subset to produce the target as product



*  Taylor's Theory: 
*  (Possibly recurrsive program?)
*  Call a function with an array, and target number
*  If array at index is 0 -> skip it
*  If we can find a number such that target number % array at index is 0
*    -> First number becomes the array at index
*    -> target number becomes target number / First number
*    -> array at index becomes 0
*      -> call the function with the new array, and target number (Should be simpler to check through?)
*  If we don't, then the target number does not have a subset of array ints that will produce it as a product
*/


//TODO: Fix return type
void findSubsetProduct(int arr[]&, int);

int main(){
  
  return 0;
}

void findSubsetProduct(int arr[]& 

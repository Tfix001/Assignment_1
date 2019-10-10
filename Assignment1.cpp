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
*  Call a function with an array, a target number, and a subsetArray? (Not sure how to get the subset otherwise)
*  --Either check if the array is empty here or in the main function
*    If array at index is 0 -> skip it
*    If we can find a number such that target number % array at index is 0
*      -> newNumber becomes the array at index
*      -> subsetArray gets the newNumber
*      -> If subsetArray product does not equal target number
*        -> target number becomes target number / newNumber
*        -> array at index becomes 0
*        -> call the function with the new array, and target number (Should be simpler to check through?)
*      -> Else the product does equal target number and we can return the subsetArray.
*    Else the target number does not have a subset of array ints that will produce it as a product
*  End Call
*/


//TODO: Fix return type
void findSubsetProduct(int userArr[]&, int, int subsetArr[]&);

int main(){
  //user inputs an array 
    //(May need some assistance with understanding arrays, I'm more used to vectors) - Taylor
  //user inputs an additional number, being the target number
  //call findSubsetProduct
  //output the subset and the product of subset (Which should hopefully be the initial target number
  return 0;
}

void findSubsetProduct(int userArr[]&, int target){
}

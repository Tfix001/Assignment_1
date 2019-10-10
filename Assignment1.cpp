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

37
16 2 1 37
1 2 16 37

*  Taylor's Theory: 
*  (Possibly recurrsive program?)
*  Call a function with an array(NOT BY REFERENCE), and target number
*  If we can find a number such that target number % array[index] == 0
*    -> First number = array[index]
*    -> target number = target number / First number
*    -> array[index] = 0
*      -> call the function with the new array, and target number
*  If we don't, then the target number does not have a subset of array ints that will produce it as a product
*/

int main(){
  //First idea: 
  return 0;
}

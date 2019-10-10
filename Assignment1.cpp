/*
* Assignment 1
* Written by: Taylor Fix, Jacob Liu, Yuta Nakamura
* Usage: To check whether a given expression is a polynomial or not
* Restrictions:
*   - All multiplication between numbers and variables are assumed to be resolved before being entered
*     eg) Instead of 3*2, assume input 6. Likewise, instead of n*n*n, assume input n^3
*   - Variables within the expression must be consistant within the expression
*   - All variables are assumed to be denoted by 'n'
*
*
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*----------- Function Prototypes -----------*/
// Function to remove whitespace
string removeWhiteSpace(string input);
// Function to see if the expression is a valid polynomial
bool isPolynomial(string input);


/*----------- Main Function -----------*/
int main() {
  // This is the user input
  string userPoly;
  // Gets the input from the user
  getline(cin, userPoly);
  // Remove the whitespace from the string
  userPoly = removeWhiteSpace(userPoly);

  if (isPolynomial(userPoly))
  {
    cout << "This is a valid polynomial." << endl;
  }
  else
  {
    cout << "This is not a valid polynomial." << endl;
  }


}

/*---------- Function Definition ----------*/
// Removes the white space within the string
string removeWhiteSpace(string input)
{
  // New string without the whitespace.
  string noWhitespace;
  // The new position that the int is going to take in the temp string
  int newPosition = 0;
  // For the length of the string
  for (int i = 0; i < input.length(); i++)
  {
    // If the char in the string is not a whitespace
    if (input[i] != ' ')
    {
      // Copy that into the new string
      noWhitespace += input[i];
    }
  }
  return noWhitespace;
}

// Returns if the expression is a polynomial
bool isPolynomial(string userPoly){
  // This is assuming that the polynomial starts with 'n' or a number
  char state = 'A';
  bool isPolynomial = 1;

  // For the length of the entire polynomial
  for(int i = 0; i < userPoly.length() + 1; i++) {
    switch(state)
    {
      case 'A':
        if(isdigit(userPoly[i])){ // If the character is a number
          state = 'C';
        }
        else if (userPoly[i] == 'n'){ // If the character is 'n'
          state = 'B';
        }
        else { // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'B':
        if(userPoly[i] == '+') { // If the character is '+'
          state = 'A';
        }
        else if(userPoly[i] =='^'){ // If the character is '^'
          state = 'G';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'C': //there is a self loop
        if(isdigit(userPoly[i])) { // If the char is a number
          state = 'C';
        }
        else if(userPoly[i] == '.'){ // If the char is a '.'
          state = 'D';
        }
        else if(userPoly[i] == '*'){ // If the char is a '*'
          state = 'F';
        }
        else if(userPoly[i] == '+'){ // If the char is a '+'
          state = 'A';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'D':
        if(isdigit(userPoly[i])){  // If the char is a number
          state = 'E';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'E':
        if(isdigit(userPoly[i])){  // If the char is a number
          state = 'E';
        }
        else if(userPoly[i] == '*'){  // If the char is a '*'
          state = 'F';
        }
        else if(userPoly[i] == '+'){ // If the char is a '+'
          state = 'A';
        }
        else { // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'F':
        if(userPoly[i] == 'n'){ // If the char is a 'n'
          state = 'H';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'G':
        if(isdigit(userPoly[i])){ // If the char is a number
          state = 'I';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'H':
        if(userPoly[i] =='^') { // If the char is a '^'
          state = 'I';
        }
        else if ( userPoly[i] == '+') { // If the char is a '+'
          state = 'A';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      case 'I':
        if(isdigit(userPoly[i])){ // If the char is a number
          state = 'I';
        }
        else if (userPoly[i] == '+'){ // If the char is a '+'
          state = 'A';
        }
        else{ // If it does not meet this criteria, go to default state and return false
          state = 'Z';
        }
        break;

      // The expression is deemed not to be a polynomial when it does not fit the above criterias
      default:
        isPolynomial = 0;
        break;
     }
   }

  // If the last character in the string is '.', '+', or '*' then return that it is not a polynomial
   if(userPoly.size() > 0){
        if(!isdigit(userPoly[userPoly.length() - 1]) && userPoly[userPoly.length() - 1] != 'n'){
            isPolynomial = 0;
        }
   }

   return isPolynomial;
}

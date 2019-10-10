/*
* Assignment 1
* Written by: Taylor Fix, Jacob Liu, Yuta Nakamura
*  
*  
*  
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // This is the user input
  string userPoly;
  // Gets the input from the user
  getline(cin, userPoly);
  // This is assuming that the polynomial starts with 'n' or a number
  char state = 'A';

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
        cout << "Invalid Polynomial" << endl;
        return false;
        break;
     }
   }
   
  // If the last character in the string is '.', '+', or '*' then return that it is not a polynomial
   if(userPoly.size() > 0){
        if(!isdigit(userPoly[userPoly.length() - 1]) || userPoly[userPoly.length() - 1] != 'n'){
            cout << "Invalid Polynomial" << endl;
            return false;
        }
   }
}

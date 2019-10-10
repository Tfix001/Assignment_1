//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
//Outside sources: Steven Calvert, Michael Ching (Gave us the idea to use a Finite State Machine)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findDegrees(string);
string getHighestDegree(string);
string removeWhiteSpace(string);
bool isPolynomial(string);

/*
Assuming...
Expression cannot start with '.', at least "0."
Expressions do not include '/'
The variable is 'n'
Expressions do not include special characters i.e. '@', '!'
All multiplication between numbers and variables are assumed to be resolved before being entered i.e. 16 not 4*4 and n^3 not n*n*n
The coeffecient won't be after the variable. "n * 2" /
No log functions
*/

int main(){
  //Check invalidity i.e. Check for negation and/or parathesis --
  //Check validity i.e. Check for summation and/or multiplication --
  //Second check for invalidity i.e. n^3n && n^4.2 --
  string userPoly;
  getline(cin, userPoly);
  userPoly = removeWhiteSpace(userPoly);

  if (isPolynomial(userPoly)){
    //cout << "This is a valid polynomial." << endl;
  }
  else{
    //cout << "This is not a valid polynomial." << endl;
    return 0;
  }

  string polyDegrees = findDegrees(userPoly);
  string highestDegree = getHighestDegree(polyDegrees);

  if((highestDegree != "0") && (highestDegree != "-1")){
    cout << "O(n^" << highestDegree << ')' << endl;
  }
  else if(highestDegree == "0"){
    cout << "O(1)" << endl;
  }
  else{
    cout << "Invalid Polynomial (Due to repeating degrees)" << endl;
  }

  return 0;
}


string findDegrees(string poly){
  string newString = "";
  unsigned index;
  for(unsigned i = 0; i < poly.length(); i++){
    index = poly.find("n", i);
    if(index > poly.length()){
        break;
    }
    if(poly[index + 1] == '^'){
        for(unsigned j = index + 1; poly[j] != '+'; j++){
            newString += poly[j];
        }
    }
    else{
        newString += "1";
    }
    newString += " ";
    i = index;
  }
  if(newString == ""){
    newString = "0";
  }
  return newString;
}

string getHighestDegree(string strOfExp){
  //take the string we made last time and make it into a vector
  vector<string> vecOfExp;
  int i = 0;
  int ind = strOfExp.find(" ");
  while(i < strOfExp.length()){
    if(ind > strOfExp.length()){
        ind = strOfExp.length();
    }
    vecOfExp.push_back(strOfExp.substr(i, ind - i));
    i = ind + 1;
    ind = strOfExp.find(" ", i);
  }
  if(vecOfExp.size() > 1){
    unsigned maxDegree = 0;
    for(unsigned i = 1; i < vecOfExp.size(); i++){
        for(unsigned j = 0; j < vecOfExp.size(); j++){
            if(j != i){
                if(vecOfExp.at(j) == vecOfExp.at(i)){
                    return "-1";
                }
            }
        }
        //Check size to see if max is the same as i i.e. max = "3" i = "7"
        if((vecOfExp.at(maxDegree).size()) == (vecOfExp.at(i)).size()){
            //Check both strings to see if i is greater than maxDegree i.e. I = "7" maxDegree = "3"
            if(vecOfExp.at(maxDegree) < vecOfExp.at(i)){
                maxDegree = i;
            }
            //Completes part C.
        }
        //Check size to see if maxDegree is less than i i.e. max = "9" i = "12"
        else if((vecOfExp.at(maxDegree).size()) < (vecOfExp.at(i)).size()){
            maxDegree = i;
        }
    }
    return vecOfExp.at(maxDegree);
  }
  else if(vecOfExp.size() == 1){
    return vecOfExp.at(0);
  }
  else{
    return "0";
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
          state = 'G';
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

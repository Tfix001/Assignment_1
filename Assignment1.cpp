#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string userPoly;
  char state = 'A';
  for(int i = 0; i<userPoly.length(); i++) {
    switch(state):
    case 'A':
      if(isdigit(userPoly[i]){ // If the character is a number
        state = 'C';
      }
      else if (userPoly[i] == 'n'){ // If the character is 'n'
        state = 'B';
      }
      else{
        state = 'Z';
      }
      break;

    case 'B':
      if(userPoly[i] == '+'') { // If the character is '+'
        state = 'A';
      }
      else if(userPoly[i] =='^'){ // If the character is '^'
        state = 'G'
      }
      else{
        state = 'Z';
      }
      break;

    case 'C': //there is a self loop
      if(isdigit(userPoly[i])) {
        state = 'C';
      }
      else if(userPoly[i] == '.'){
        state = 'D';
      }
      else if(userPoly[i] == '*'){
        state = 'F';
      }
      else{
        state = 'Z';
      }
      break;

    case 'D': //dont need to touch
      if(isdigit(userPoly[i])){
        state = 'E';
      }
      else{
        state = 'Z';
      }
      break;

    case 'E': // there is a self loop
      if(isdigit(userPoly[i])){
        state = 'E';
      }
      else if(userPoly[i] == '*'){
        state = 'F';
      }
      else if(userPoly[i] == '+'){
        state = 'A';
      }
      else {
        state = 'Z'
      }
      break;
    
    case 'F':
      if(userPoly[i] == 'n'){
        state = 'H';
      }
      else{
        state = 'Z';
      }
    break;

    case 'G':
      if(isdigit(userPoly[i])){
        state = 'I';
      }
      else{
        state = 'Z'; 
      }
    break;

    case 'H':
      if(userPoly[i] =='^') {
        state = 'I';
      }
      else if ( userPoly[i] == '+') {
        state = 'A';
      }
      else{
        state = 'Z';
      }
    break;

    case 'I': //self loop
      if(isdigit(userPoly[i]){
        state = 'I';
      }
      else if (userPoly[i] == '+'){
        state = 'A';
      }
      else{
        state = 'Z';
      }
    break;

    default:
    cout << "Invalid Polynomial" << endl;
    return false;
    break;
   }
}

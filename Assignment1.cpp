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
      if(isdigit(userPoly[i]) || userPoly[i] == 'n'){

      }
    break;
    case 'B':
      if(userPoly[i] == '+' || userPoly[i] =='^') {

      }
    break;
    case 'C': //there is a self loop
      if(isdigit(userPoly[i]) || userPoly[i] == '.' || userPoly[i] == '*') {

      }
    break;
    case 'D': //dont need to touch
      if(isdigit(userPoly[i]))
    break;
    case 'E': // there is a self loop
      if(isdigit(userPoly[i])|| userPoly[i] == '*' || userPoly[i] == '+'){

      }
    break;
    case 'F':
      if(userPoly[i] == 'n'){

      }
    break;
    case 'G':
      if(isdigit(userPoly[i])){

      }
    break;
    case 'H':
      if(userPoly[i] =='^') {

      } else if ( userPoly[i] == '+') {

      }
    break;
    case 'I':
      if(isdigit(userPoly[i]){

      } else if (userPoly[i] == '+'){

      }
    break;
    default:
    break;

}
}

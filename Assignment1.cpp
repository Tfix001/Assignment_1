//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
#include <iostream>
#include <string>

using namespace std;

bool isValid(string);

int main(){
  //Check invalidity i.e. Check for negation and/or parathesis --
  //Check validity i.e. Check for summation and/or multiplication --
  //Second check for invalidity i.e. n^3n && n^4.2 --
  string userPoly;
  char degree = '0';
  bool valid = false;
  getline(cin, userPoly);
  //Assuming variable is only n
  if(userPoly.length() == 1){
    if(userPoly.at(0) == 'n'){
      degree = '1';
    }
    else if(isDigit(userPoly.at(0))){
      degree = '0';
    }
    else{
      cout << "Invalid Input" << endl;
      return 0;
    }
  }
  else{
    valid = isValid(userPoly);
    if(valid){
      //Used to look for highest degree
      for(unsigned i = 0; i < userPoly.length(); i++){
      }
    }
    else{
      cout << "Invalid Input" << endl;
      return 0;
  }
  
  //Check for highest degree (aka Big-O notation) --
  // If the length of the input expression is m chars, what is the big-Oh complexity of your program with respect to m? --
  
  //What if we require that there is only one term for each degree? --
    //That is, (ii) above is invalid because it has two terms for degree 1 (n^1).
  return 0;
}

bool isValid(string userString){
  return false;
}

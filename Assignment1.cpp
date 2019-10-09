//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
#include <iostream>
#include <string>

using namespace std;

bool inValid(string);

int main(){
  //Check invalidity i.e. Check for negation and/or parathesis --
  //Check validity i.e. Check for summation and/or multiplication --
  //Second check for invalidity i.e. n^3n && n^4.2 --
  string userPoly;
  getline(cin, userPoly);
  for(unsigned i = 0; i <= userPoly.length(); i++){
    //Check string for top three
    //Can also be used to look for highest degree
  }
  
  //Check for highest degree (aka Big-O notation) --
  // If the length of the input expression is m chars, what is the big-Oh complexity of your program with respect to m? --
  
  //What if we require that there is only one term for each degree? --
    //That is, (ii) above is invalid because it has two terms for degree 1 (n^1).
  return 0;
}

bool inValid(string userString){
  
}

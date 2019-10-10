//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
//Outside sources: Steven Calvert, Michael Ching (Gave us the idea to use a Finite State Machine)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findDegrees(string);

/*
Assuming...
Expression cannot start with '.', at least "0."
Expressions do not include '/'
The variable is 'n'
Expressions do not include special characters i.e. '@', '!'
Integers will not multiply with each other i.e. 4*4
The coeffecient won't be after the variable. "n * 2" / 
No log functions
*/

int main(){
  //Check invalidity i.e. Check for negation and/or parathesis --
  //Check validity i.e. Check for summation and/or multiplication --
  //Second check for invalidity i.e. n^3n && n^4.2 --
  string userPoly;
  getline(cin, userPoly);
      return 0;
  }
  return 0;
}


string findDegrees(string userPoly){
  string newString;
  for(int i = 0; i< userPoly.length(); i++){
    i = userPoly.find("n", i){
    if(userPoly[i++]=='^'){
      for(int j = i+2;(userPoly[j]!='+') || (j!= userPoly.length); j++) {
        newString+=userPoly[j];
      }
      newString+=" ";
    }
    else {
      newString +='1';
      newString +=" ";
    }
  }
}
  if(newString.isEmpty()) {
    newString = "0";
  }
}


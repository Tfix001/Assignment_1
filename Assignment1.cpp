//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
//Outside sources: Steven Calvert, Michael Ching (Gave us the idea to use a Finite State Machine)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findDegrees(string);
string getHighestDegree(string);

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

string getHighestDegree(string strOfExp){
  //take the string we made last time and make it into a vector
  string strOfExp = "11 3 5 12";
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
        //Check size to see if max is the same as i i.e. max = "3" i = "7"
        if((vecOfExp.at(maxDegree).size()) == (vecOfExp.at(i)).size()){
            //Check both strings to see if i is greater than maxDegree i.e. I = "7" maxDegree = "3"
            if(vecOfExp.at(maxDegree) < vecOfExp.at(i)){
                maxDegree = i;
            }
            //Completes part C.
            else if(vecOfExp.at(maxDegree) == vecOfExp.at(i)){
                return "-1";
            }
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

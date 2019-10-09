//Names: Jacob Liu, Taylor Fix, Yuta Nakamura
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string userPolynomial, vector<string> &polyTerms);

int main(){
  // The variable for the user inputted polynomial
  string userPoly;
  // The vecotr that is going to store each individual term
  vector<string> polyTerms;

  vector<string>::iterator it1;
  // Gets the user input
  getline(cin, userPoly);
  // Test for isValid
  cout << isValid(userPoly, polyTerms) << endl;

/*
  for (int i = 0; i < polyTerms.size(); i++){
    cout << polyTerms.at(i) << endl;
  }
*/

  for(it1 = polyTerms.begin(); it1 != polyTerms.end(); it1++) {
    cout << *it1 << endl;
  }
  return 0;
}

bool isValid(string userPolynomial, vector<string> &polyTerms){
  // The position of the '+' symbol
  int positionOfPlus = 0;
  string term;

  // If there is '-', '(', ')' the polynomial is automatically invalid
  for (int i = 0; i < userPolynomial.length(); i++){
    if (userPolynomial[i] == '-' || userPolynomial[i] == '(' || userPolynomial[i] == ')'){
      return false;
    }
  }

  // If is does not include '-', '(', ')'
  for (int j = 0; j < userPolynomial.length(); j++){
    cout << "Runs up to here 1" << endl;
    positionOfPlus = userPolynomial.find("+", j);
    // If there are no more '+' symbols to look for
    if (positionOfPlus == string::npos){
      positionOfPlus = userPolynomial.length();
    }
    cout << "Runs up to here 2" << endl;
    // Store 1 term
    for (int i = j; i < positionOfPlus; i++){
      cout << "Runs up to here 3" << endl;
      term[i] = userPolynomial[i];
      cout << term[i] << endl;
    }
    cout << "Runs up to here 4" << endl;
    // Store the term into the vector
    polyTerms.push_back(term);

    j = positionOfPlus;

  }
  return false;
}

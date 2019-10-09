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
  // Gets the user input
  getline(cin, userPoly);
  // Test for isValid
  cout << isValid(userPoly, polyTerms) << endl;

  // Print the contents of polyTerms
  for (int i = 0; i < polyTerms.size(); i++){
    cout << polyTerms.at(i) << endl;
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

  // If is does not include '-', '(', ')' split the expression into each term
  for (int j = 0; j < userPolynomial.length(); j++){
    positionOfPlus = userPolynomial.find("+", j);
    // If there are no more '+' symbols to look for
    if (positionOfPlus == string::npos){
      positionOfPlus = userPolynomial.length();
    }
    // Store 1 term
    for (int i = j; i < positionOfPlus; i++){
      term += userPolynomial[i];
    }
    // Store the term into the vector
    polyTerms.push_back(term);

    j = positionOfPlus;
    term.clear();
  }

  return false;
}

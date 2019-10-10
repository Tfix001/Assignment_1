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
                return -1;
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

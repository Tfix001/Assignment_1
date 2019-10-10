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

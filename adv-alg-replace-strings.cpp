# include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;



//function to replace strings in myString per specifications found in myPairs
//will use a brute force algorithm
string replaceSubs(string myString, string find, string replace){
//string replaceSubs(string myString, string myreplace[]){
  string myReplace [] = {find, replace};
  string modString = myString;
  int matchFound = 1; //counter to see if a match is found
  int i =0;
  while (matchFound == 1 && i<(myString.length()-myReplace[0].length())){
    if (myString[i]==myReplace[0][0]){
      int isMatch = 0; //will be changed to 1 when no longer matching string to be replaced
      int j = 1; //used to iterate over string to be replaced
      while (isMatch ==0 && j<myReplace[0].length()){
        if (myString[i+j] != myReplace[0][j]){
          isMatch = 1;
        }
        else {
          j++;
        }
      }
      cout<<"isMatch: "<<isMatch<<endl;
      /*
          //if isMatch == 0 switch use substr() conctatenation to replace myString with modified myString

      */

      cout<<"starts from "<<i<<" until "<<j<<endl;
      if (isMatch==0){
        //myString[i:]
        modString = myString.substr(0,i) + myReplace[1] + myString.substr(i+j,myString.length());
        cout<<" modString is: "<<modString<<endl;
        //myString[:] = myReplace[1][0:myReplace[1].length()]
      }
    }
    i++;
  }
  return modString;
}

string replaceSubs1(string myString, string myReplace[]){
  string modString = myString;
  //for (int i = 0; i<(sizeof(myReplace)/sizeof(myReplace[0])); i++){
  for (int i = 0; i< 9; i=i+2){
    modString = replaceSubs(modString, myReplace[i], myReplace[i+1]);
  }
  return modString;
}


int main(){
  string input1 = "My dear Anna, let me congratulate you on the beautiful car that you purchased today. It looks very posh. I hope you got a good deal. Cars are expensive but much needed. Best regards, Naomi.";
  string inputPairs[]={"Anna", "Jovi and Victor"};
  string inputPairs1[4][2]={ {"Anna", "Jovi and Victor"} , { "car", "house"}, {"today", "last week"}, {"posh", "well built"}};
  //array< array<string,2>, 4> inputPairs2[4][2]={ {"Anna", "Jovi and Victor"} , { "car", "house"}, {"today", "last week"}, {"posh", "well built"}};
  //cout<<"The size of the array is "<<sizeof(inputPairs1)/sizeof(inputPairs1[0])<<endl;
  string testString = replaceSubs1(input1, inputPairs);
  cout<<testString<<endl;
  cout<<"InputPair1[0][0] is: "<<inputPairs[1]<<endl;
  return 0;
}

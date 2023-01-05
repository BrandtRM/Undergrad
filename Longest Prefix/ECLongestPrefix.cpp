#include "ECLongestPrefix.h" 
#include <iostream>
#include <string.h>

using namespace std;

// Implement the longest prefix function here...
std::string ECLongestPrefix(int numStrings, const std::string arrayStrings[])
{
  // YW: this only serves as a starter code, which just print out the given array of strings
  // Replace with your own code here...
  /*
  for(int i=0; i<numStrings; ++i)
  {
    cout << arrayStrings[i] << " ";
  }
  cout << endl;
  */
  int shortlen = 1000;
  
  for(int i=0; i<numStrings; ++i)
  {
    string x = arrayStrings[i];
    if(x.length() < shortlen){
        shortlen = x.length();
    }
  }
  
  int error = 0;
  string prefix;
  string result = "";
  
  for(int j = 1; j < shortlen + 2; ++j)
  {
    if(error == 0){
        result = prefix;
        prefix = arrayStrings[0].substr(0, j);
    }
    else{
        break;
    }
    
    for(int i = 0; i < numStrings; ++i)
    {
        if(prefix != arrayStrings[i].substr(0, j)){
            error = 1;
        }
    }
  }
  return result;
}


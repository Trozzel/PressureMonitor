//
// Created by George Ford on 10/18/21.
//
#include "helper.h"

string handleNumStr(const string& numberString)
{
  string numStr { numberString };

  // REMOVE \r\n
  while (numStr.back() == '\r' || numStr.back() == '\n')
    numStr.pop_back();

  // 1. IS POSITIVE?
  bool isPositive = numStr[0] == '+';
  numStr.erase(0,1); // remove the sign (+,-)

  // 2. DETERMINE IF GREATER THAN 1
  size_t pos = numStr.find('E');
  bool lessThanOne = numStr[pos+1] == '-';
  string powerStr = numStr.substr(pos+2, numStr.size()); // remove sign and 'E'
  numStr.erase(pos, numStr.size());
  int powLevel = lexical_cast<int>(powerStr);

  // 3. REMOVE DECIMAL POINT
  pos = numStr.find('.');
  numStr.erase(pos,1);

  // 4. HANDLE THE DECIMAL PLACEMENT
  if (lessThanOne)
    for(int i = 0; i < powLevel-1; ++i)
      numStr.insert( 0 ,"0");
  else
    for(int i = 0; i < powLevel; ++i)
      numStr.insert( numStr.size() ,"0");

  return numStr;
}
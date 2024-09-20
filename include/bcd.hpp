#ifndef __BCD_HPP__
#define __BCD_HPP__

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using uint = unsigned;
using namespace std;

/*                              DECLARATIONS                                  */
/******************************************************************************/
static std::string removeDecimal(const std::string& numstr);

template<uint Width>
std::vector<std::vector<bool> > getBcdVector_(std::string& numstr);

ostream& operator<<(ostream& out, vector<vector<bool> >& array);
/******************************************************************************/

/*                               DEFINITIONS                                  */
// REMOVE DECIMAL
/******************************************************************************/
static string removeDecimal(const string& numstr)
{
  string newNumStr{numstr};
  size_t loc = numstr.find('.');
  if(loc != string::npos)
    newNumStr.replace(loc, 1, "");
  return newNumStr;
}


// GET BCD ARRAY
/******************************************************************************/
template<uint Width>
vector<vector<bool> > getBcdVector_(const string& numstr)
{
  string noSignStr(numstr.size() - 1, '\0');
  bool positive = numstr.front() == '+';
  std::copy(numstr.begin()+1, numstr.end(), noSignStr.begin());

  vector<vector<bool> > digOutValues(Width);
  string newNumStr{removeDecimal(noSignStr)};

  int num {stoi(newNumStr)};
  int singleDig;
  for (int dioSet=0; dioSet < Width; ++dioSet)
  {
    vector<bool> array(4);
    singleDig = num % 10; // yield remainder of 10 division
    num     = static_cast<int>(floor(static_cast<float>(num/10)));
    for (int i=0; i<4; ++i)
    {
      // bitwise comparison for each digit
      if (1 & singleDig)
        array[i] = true;
      else
        array[i] = false;
      singleDig >>= 1;
    }
    std::reverse(array.begin(), array.end());
    digOutValues[dioSet] = array;
  }

  if (positive)
    digOutValues[Width-1][0] = true;
  return digOutValues;
}



#endif // __BCD_HPP__

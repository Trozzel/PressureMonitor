//
// Created by George Ford on 10/7/21.
//

#include "bcd.hpp"

using namespace  std;

ostream& operator<<(ostream& out, vector<vector<bool>>& array)
{
  cout << "NUM    3   2   1   0" << endl;
  cout << string(22, '-') << endl;
  int count {0};
  for(auto& row : array)
  {
    cout << setw(2) << count++ << ": ";
    for(bool val : row)
    {
      out << setw(4);
      out << ((val) ? 1 : 0);
    }
    out << endl;
  }
  return out;
}

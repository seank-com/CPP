//////////////////////////////////////////////////////////////////////
// A little program to demonstrate working with iostream for input
// and output.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main()
{
  vector<int> vec;

  cout << "Enter integers separated by spaces & then\na character ( try example: '2 4 6 8 a' ): ";

  istream_iterator<int> it(cin);
  copy(it, istream_iterator<int>(), back_inserter(vec));
  cin.clear();

  cout << "vec = ";
  for (auto i = vec.begin( ) ; i != vec.end( ) ; i++ )
    cout << *i << " "; cout << endl;

  stringstream ss;

  ss << "This is a test " << 123 << " lets see how bad it gets" << endl;

  cout << ss.str();

  while(ss)
  {
    string sub;
    ss >> sub;
    cout << "got " << sub << endl;
  }
}

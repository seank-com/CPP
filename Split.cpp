//////////////////////////////////////////////////////////////////////
// A STL implementation of the Split function from Javascript.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void split(const string& source, const char separator, vector<string>& dest)
{
  auto last = source.begin();
  for(auto i = source.begin(); i != source.end(); i++ )
  {
    if( *i == separator )
    {
      dest.push_back(string(last,i));
      last = i;
      last++;
    }
  }
  if(last != source.end())
    dest.push_back(string(last, source.end()));
}

int main()
{
  string test = "This is a test of the emergency broadcast system.";

  vector<string> words;
  split(test, ' ', words);

  for(auto t = words.begin(); t != words.end(); t++)
    cout << *t << endl;
}

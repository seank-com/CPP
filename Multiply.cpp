//////////////////////////////////////////////////////////////////////
// Ever wondered how a computer can multiply. Well wonder no more.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

template <class T> string AsString(const T& t)
{
	stringstream s;
	s << t;
	return s.str();
}

template <class T> ostream& operator << (ostream& os, const vector<T>& t)
{
  os << "{";
  for (vector<T>::size_type i = 0; i < t.size(); i++) os << (i ? ", " : "") << t[i];
  os << "}";
  return os;
}

template<class S,class T> ostream& operator << (ostream &os ,const pair<S,T>& a)
{
  os << "(" << a.first << ", " << a.second << ")";
  return os;
}

int Multiply(int a, int b)
{
	int result = 0;
	if (a < (1<<16) && b < (1<<16))
	{
		for(int i = 0; i < 16; i++)
			result += ((b & (1 << i)) == (1 << i)) ? a << i : 0;
	}
	return result;
}

int main()
{
	for(int a = 0; a < (1<<16); a++)
	{
		for(int b = 0; b < (1<<16); b++)
		{
			if (Multiply(a,b) != a*b)
			{
				cout << "ERROR:" << a << "*" << b << "!=" << a*b << endl;
			}
		}
		if (a % 100 == 0)
			cout << a << endl;
	}
}

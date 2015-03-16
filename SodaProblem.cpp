//////////////////////////////////////////////////////////////////////
// From an interview question someone told me about.
//
// You got this Soda machine that dispenses soda with three buttons.
// One button dispenses somewhere between 250 and 260 ounces
// One button dispenses somewhere between 360 and 375 ounces
// One button dispenses somewhere between 510 and 530 ounces.
//
// Write a program to determine the buttons to press to fill a
// 2000 ounce container with atleast 1900 ounces of soda without
// spilling any.
//

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

struct Button
{
	Button(int min, int max)
	{
		Min = min;
		Max = max;
	}

	int Min;
	int Max;
};

vector<int> Fill(int min, int max, vector<int> sofar, vector<Button>& buttons)
{
	cout << string(sofar.size()*4,' ') << "min = " << min << ", max = " << max << ", sofar = " << AsString(sofar) << endl;
	for(int i = 0; i < buttons.size(); i++)
	{
		vector<int> sample = sofar;
		int nmin = min - buttons[i].Min;
		int nmax = max - buttons[i].Max;
		sample.push_back(i);

		cout << string(sofar.size()*4,' ') << "i = " << i << ", nmin = " << nmin << ", nmax = " << nmax << endl;

		if (nmin < 0 && nmax > 0)
		{
			cout << string(sofar.size()*4,' ') << "FOUND IT" << endl;
			return sample;
		}

		if (nmin > 0)
		{
			vector<int> solution = Fill(nmin, nmax, sample, buttons);
			if (solution.size() > 0)
			{
				cout << string(sofar.size()*4,' ') << "FOUND IT" << endl;
				return solution;
			}
		}
	}

	vector<int> result;
	return result;
}

int main()
{
	vector<int> sofar;
	vector<Button> buttons;

	buttons.push_back(Button(250, 260));
	buttons.push_back(Button(360, 375));
	buttons.push_back(Button(510, 530));

	cout << AsString(Fill(1900, 2000, sofar, buttons)) << endl;
}

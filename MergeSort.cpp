//////////////////////////////////////////////////////////////////////
// An implementation of a merge sort algorithm that my son was
// learning about in his programming class. This is different from
// the merge sorts I learned about back in school.

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

void Merge(vector<int>& A, int p, int q, int r)
{
	vector<int> L(q - p + 2);
	vector<int> R(r - q + 1);

	for(int i = 0; i < L.size()-1; i++) L[i] = A[p + i];
	for(int j = 0; j < R.size()-1; j++) R[j] = A[q + 1 + j];

	int i = 0, j = 0;
	L[L.size()-1] = INT_MAX;
	R[R.size()-1] = INT_MAX;
	for(int k = p; k <= r; k++)
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
}

void MergeSort(vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main()
{
	int set[] = { 5, 7, 9, 10, 11, 13, 4, 8, 1, 3, 2, 6, 12};
	vector<int> a;
	a.assign(set, end(set));

	cout << AsString(a) << endl;

	MergeSort(a, 0, a.size()-1);

	cout << AsString(a) << endl;
}

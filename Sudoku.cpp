//////////////////////////////////////////////////////////////////////
// A little program that solves a sudoku board.

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

vector<int> ValidValues(const vector<vector<int>>& board, int x, int y)
{
	vector<int> result;
	for(int v = 1; v < 10; v++)
	{
		int x1, y1;
		bool valid = true;

		for(x1 = 0; x1 < 9; x1++)
		{
			if (x != x1 && v == board[x1][y])
			{
				valid = false;
			}
		}

		for(y1 = 0; y1 < 9; y1++)
		{
			if (y != y1 && v == board[x][y1])
			{
				valid = false;
			}
		}

		for(int xp = 0; xp < 3; xp++)
		{
			for(int yp = 0; yp < 3; yp++)
			{
				x1 = xp + (3*(x/3));
				y1 = yp + (3*(y/3));

				if (x != x1 && y != y1 && v == board[x1][y1]) valid = false;
			}
		}

		if (valid)
		{
			result.push_back(v);
		}
	}
	return result;
}

bool sudoku_solution(vector<vector<int>>& board)
{
	vector<int> values, bestvalues;
	int bestx = -1, besty = -1;
	for(int x = 0; x < 9; x++)
	{
		for(int y = 0; y < 9; y++)
		{
			if(board[x][y] < 1)
			{
				if (bestx < 0)
				{
					bestx = x; besty = y;
					bestvalues = ValidValues(board, x, y);
				}
				else
				{
					values = ValidValues(board, x, y);
					if (values.size() == 0)
						return false;

					if (values.size() < bestvalues.size())
					{
						bestx = x;
						besty = y;
						bestvalues = values;
					}
				}
			}
		}
	}

	if (bestx == -1)
		return true;

	for(vector<int>::size_type i = 0; i < bestvalues.size(); i++)
	{
		board[bestx][besty] = bestvalues[i];
		if (sudoku_solution(board)) return true;
			board[bestx][besty] = 0;
	}

	return false;
}


int main()
{
	vector<vector<int>> board(9);

	board[0].assign(9, 0);
	board[1].assign(9, 0);
	board[2].assign(9, 0);
	board[3].assign(9, 0);
	board[4].assign(9, 0);
	board[5].assign(9, 0);
	board[6].assign(9, 0);
	board[7].assign(9, 0);
	board[8].assign(9, 0);

	if (sudoku_solution(board))
	{
		cout << AsString(board[0]) << endl;
		cout << AsString(board[1]) << endl;
		cout << AsString(board[2]) << endl;
		cout << AsString(board[3]) << endl;
		cout << AsString(board[4]) << endl;
		cout << AsString(board[5]) << endl;
		cout << AsString(board[6]) << endl;
		cout << AsString(board[7]) << endl;
		cout << AsString(board[8]) << endl;
	}
}

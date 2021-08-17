#include <bits/stdc++.h>

using namespace std;

constexpr int N = int(100) + 1;
using ll = long long;
using ull = unsigned long long;

char tab[N][N];

bool check_rows(size_t rows, size_t cols)
{
	for (size_t row = 0; row < rows; row++)
	{
		if (std::adjacent_find(tab[row], tab[row] + cols, std::not_equal_to<>()) !=
			tab[row] + cols)
		{
			return false;
		}
	}
	int last_row = 0;
	int count = 0;
	int length = 0;
	std::set<char> colors;
	for (size_t row = 1; row < rows + 1; ++row)
	{
		if (row == rows || tab[row][0] != tab[row - 1][0])
		{
			int new_length = row - last_row;
			if (length != 0 && length != new_length)
			{
				return false;
			}
			length = new_length;
			last_row = row;
			count++;
			colors.insert(tab[row - 1][0]);
			if (count > 3)
			{
				return false;
			}
		}
	}
	return colors.size() == 3;
}

int main(void)
{

	size_t rows, cols;
	cin >> rows >> cols;
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			cin >> tab[row][col];
		}
	}

	bool is_ok = check_rows(rows, cols);
	for (size_t row = 0; row < std::max(rows, cols); row++)
	{
		for (size_t col = row + 1; col < std::max(rows, cols); col++)
		{
			std::swap(tab[row][col], tab[col][row]);
		}
	}
	is_ok = is_ok || check_rows(cols, rows);
	std::cout << (is_ok ? "YES" : "NO") << std::endl;
	set<int> s;
	return 0;
}
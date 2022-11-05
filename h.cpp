#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

void relaxMinSquares(int i, std::vector<int>& min_squares) {
	for (int sq = 1; sq * sq <= i; ++sq) {
		min_squares[i] = std::min(min_squares[i], min_squares[i - sq * sq] + 1);
	}
}

int getMinSquareSum(int n) 
{
	std::vector<int> min_squares(n + 1, INT_MAX);
	min_squares[0] = 0;
	for (int i = 1; i <= n; ++i) {
		relaxMinSquares(i, min_squares);
	}
	return min_squares[n];
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << getMinSquareSum(n) << '\n';
	return 0;
}
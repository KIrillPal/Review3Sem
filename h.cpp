﻿#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	const int MAXCOST = 1000001;
	std::vector<int> min_squares(n + 1, MAXCOST);
	min_squares[0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int sq = 1; sq * sq <= i; ++sq) {
			min_squares[i] = std::min(min_squares[i], min_squares[i - sq * sq] + 1);
		}
	}
	std::cout << min_squares[n] << '\n';
	return 0;
}
﻿#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> poses(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> poses[i];
	}
	std::sort(poses.begin(), poses.end());

	const int MAXCOST = 1e7;
	std::vector<int[2]> min_length(n);

	min_length[0][0] = 0;
	min_length[0][1] = MAXCOST;
	for (int i = 1; i < n; ++i)
	{
		int dist = poses[i] - poses[i - 1];

		min_length[i][0] = min_length[i - 1][1];
		min_length[i][1] = dist + std::min(
			min_length[i - 1][0],
			min_length[i - 1][1]
		);
	}

	std::cout << min_length[n - 1][1];
	return 0;
}

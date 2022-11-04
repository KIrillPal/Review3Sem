﻿#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

typedef unsigned long long ull;

int main()
{
	int n, m;
	std::cin >> n >> m;
	int costs[1000][150];
	int best_cost[1001][150];
	int best_from[1001][150];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> costs[j][i];
		}
	}

	for (int i = 0; i < n; ++i) {
		best_cost[0][i] = 0;
		best_from[0][i] = 0;
	}

	for (int j = 1; j <= m; ++j) {
		for (int i = 0; i < n; ++i) {
			int minc = 1e9 + 7;
			int minf = -1;

			if (i > 0 && minc > best_cost[j - 1][i - 1]) {
				minc = best_cost[j - 1][i - 1];
				minf = i - 1;
			}
			if (minc > best_cost[j - 1][i]) {
				minc = best_cost[j - 1][i];
				minf = i;
			}
			if (i < n - 1 && minc > best_cost[j - 1][i + 1]) {
				minc = best_cost[j - 1][i + 1];
				minf = i + 1;
			}

			best_cost[j][i] = minc + costs[j - 1][i];
			best_from[j][i] = minf;
		}
	}

	int ans_cost = best_cost[m][0];
	int ans_i = 0;

	for (int i = 1; i < n; ++i) {
		if (ans_cost > best_cost[m][i]) {
			ans_cost = best_cost[m][i];
			ans_i = i;
		}
	}

	std::vector<int> ans_cities(m);
	for (int j = m - 1; j >= 0; --j) {
		ans_cities[j] = ans_i + 1;
		ans_i = best_from[j + 1][ans_i];
	}

	for (int j = 0; j < m; ++j) {
		std::cout << ans_cities[j] << ' ';
	}

	std::cout << '\n' << ans_cost << '\n';
	return 0;
}

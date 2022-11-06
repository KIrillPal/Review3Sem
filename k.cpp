#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

#define MAX_M 1000
#define MAX_N 150

typedef unsigned long long ull;
void readCosts(int n, int m, int costs[MAX_M][MAX_N]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> costs[j][i];
		}
	}
}

void prepareDp(int n, int best_cost[MAX_M + 1][MAX_N], int best_from[MAX_M + 1][MAX_N]) {
	for (int i = 0; i < n; ++i) {
		best_cost[0][i] = 0;
		best_from[0][i] = 0;
	}
}

void fillDp(int n, int m, int best_cost[MAX_M + 1][MAX_N], int best_from[MAX_M + 1][MAX_N], int costs[MAX_M][MAX_N]) {
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
}

int getAnsFromDp(int n, int m, int best_cost[MAX_M + 1][MAX_N], int& ans_cost) {
	int ans_i = 0;
	ans_cost = best_cost[m][0];

	for (int i = 1; i < n; ++i) {
		if (ans_cost > best_cost[m][i]) {
			ans_cost = best_cost[m][i];
			ans_i = i;
		}
	}
	return ans_i;
}

void reconstructPath(int m, int best_from[MAX_M + 1][MAX_N], std::vector<int>& ans_cities, int ans_i) {
	for (int j = m - 1; j >= 0; --j) {
		ans_cities[j] = ans_i + 1;
		ans_i = best_from[j + 1][ans_i];
	}
}

void outAnswer(int m, const std::vector<int>& ans_cities, int ans_cost) {
	for (int j = 0; j < m; ++j) {
		std::cout << ans_cities[j] << ' ';
	}
	std::cout << '\n' << ans_cost << '\n';
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	int costs[MAX_M][MAX_N];
	int best_cost[MAX_M + 1][MAX_N];
	int best_from[MAX_M + 1][MAX_N];

	readCosts(n, m, costs);
	prepareDp(n, best_cost, best_from);
	fillDp(n, m, best_cost, best_from, costs);
	int ans_cost;
	int ans_i = getAnsFromDp(n, m, best_cost, ans_cost);

	std::vector<int> ans_cities(m);
	reconstructPath(m, best_from, ans_cities, ans_i);
	outAnswer(m, ans_cities, ans_cost);
	
	return 0;
}

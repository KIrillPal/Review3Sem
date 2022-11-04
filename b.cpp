﻿#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, sum;
	cin >> n;

	vector<int> nominals(n);
	for (int i = 0; i < n; ++i) {
		cin >> nominals[i];
	}

	cin >> sum;
	const int MAXCOST = 1e7;
	vector<int> costs(sum + 1, MAXCOST);
	vector<int> from(sum + 1);
	costs[0] = 0;

	for (int s = 1; s <= sum; ++s) {
		for (int i = 0; i < n; ++i) {
			if (s >= nominals[i] && costs[s] > costs[s - nominals[i]] + 1) {
				costs[s] = costs[s - nominals[i]] + 1;
				from[s] = s - nominals[i];
			}
		}
	}

	if (costs[sum] == MAXCOST) {
		cout << "-1\n";
		return 0;
	}

	cout << costs[sum] << '\n';
	while (sum > 0) {
		cout << sum - from[sum] << ' ';
		sum = from[sum];
	}
	cout << '\n';
	return 0;
}
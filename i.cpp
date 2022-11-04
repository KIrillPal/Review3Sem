﻿#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

typedef unsigned long long ull;

int main()
{
	std::string str;
	std::cin >> str;
	int n = str.size();

	std::vector<std::vector<ull> > pal_combs(n + 1, std::vector<ull>(n + 1));
	for (int i = 0; i < n; ++i) {
		pal_combs[i][i] = 1;
	}

	for (int length = 1; length <= n; ++length)
	{
		for (int l = 0; l <= n - length; ++l)
		{
			int r = l + length;

			if (str[l] == str[r - 1])
				pal_combs[l][r] += pal_combs[l + 1][r - 1];

			pal_combs[l][r] += pal_combs[l][r - 1];
			pal_combs[l][r] += pal_combs[l + 1][r];
			pal_combs[l][r] -= pal_combs[l + 1][r - 1];

		}
	}

	std::cout << pal_combs[0][n] << '\n';
	return 0;
}

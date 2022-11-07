﻿#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<long double> > combs(n + 1, std::vector<long double>(m + 1));

	combs[0][0] = 1;
	for (int dices = 1; dices <= n; ++dices)
	{
		for (int sum = dices; sum <= 6 * dices && sum <= m; ++sum)
		{
			for (int k = 1; k <= 6; ++k)
			{
				if (sum >= k)
					combs[dices][sum] += combs[dices - 1][sum - k];
			}
			combs[dices][sum] /= 6;
		}
	}
	printf("%0.10Lf\n", combs[n][m]);
	return 0;
}
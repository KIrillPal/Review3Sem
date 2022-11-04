﻿#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<bool> canwin(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			if (canwin[i - j] == false) {
				canwin[i] = true;
				break;
			}
		}
	}
	std::cout << (canwin[n] ? "First\n" : "Second\n") << '\n';
	return 0;
}

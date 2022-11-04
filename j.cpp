﻿#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

typedef unsigned long long ull;

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> ones_row(n), ones_col(n);

	std::vector<int> old_sq(n);
	std::vector<int> new_sq(n);
	int max_size = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int inch;
			scanf("%d", &inch);

			if (inch == 1) {
				ones_row[i]++;
				ones_col[j]++;
			}
			else ones_row[i] = 0, ones_col[j] = 0;

			new_sq[j] = (j > 0 ? old_sq[j - 1] + 1 : 1);
			new_sq[j] = std::min(new_sq[j], ones_row[i]);
			new_sq[j] = std::min(new_sq[j], ones_col[j]);
			max_size = std::max(max_size, new_sq[j]);
		}
		new_sq.swap(old_sq);
	}

	printf("%d\n", max_size);
	return 0;
}

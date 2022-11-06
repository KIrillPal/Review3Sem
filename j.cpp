#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

typedef unsigned long long ull;

size_t solve(size_t n) {
	std::vector<size_t> ones_row(n), ones_col(n);

	std::vector<size_t> old_sq(n);
	std::vector<size_t> new_sq(n);
	size_t max_size = 0;
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
			max_size  = std::max(max_size, new_sq[j]);
		}
		new_sq.swap(old_sq);
	}
	return max_size;
}

int main()
{
	size_t n;
	scanf("%zu", &n);
	printf("%zu\n", solve(n));
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	const int MAXN = 300;

	int n, m;
	std::cin >> n >> m;
	bool canwin[MAXN][MAXN];
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			if (i == n - 1 && j == m - 1) {
				canwin[i][j] = false;
				continue;
			}

			for (int k = j + 1; k < m; ++k) {
				if (canwin[i][k] == false) {
					canwin[i][j] = true;
					break;
				}
			}

			for (int k = i + 1; k < n; ++k) {
				if (canwin[k][j] == false) {
					canwin[i][j] = true;
					break;
				}
			}

			for (int k = 1; i + k < n && j + k < m; ++k) {
				if (canwin[i + k][j + k] == false) {
					canwin[i][j] = true;
					break;
				}
			}
		}
	}
	std::cout << (canwin[0][0] ? "F\n" : "S\n") << '\n';
	return 0;
}

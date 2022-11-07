#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 300

bool moveLine(int x, int y, int dx, int dy, int n, int m, bool canwin[MAXN][MAXN]) {
	int i = 1;
	while (x + i * dx < n && y + i * dy < m) {
		if (canwin[x + i * dx][y + i * dy] == false) {
			canwin[x][y] = true;
			return true;
		}
		++i;
	}	
	return false;
}

int main()
{

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

			if (moveLine(i, j, 0, 1, n, m, canwin))
				continue;

			if (moveLine(i, j, 1, 0, n, m, canwin))
				continue;

			if (moveLine(i, j, 1, 1, n, m, canwin))
				continue;
		}
	}
	std::cout << (canwin[0][0] ? "F\n" : "S\n") << '\n';
	return 0;
}

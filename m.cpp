#include <iostream>
#include <vector>
#include <string>

int main() {
	const int MAXN = 1000;
	const int MAXDIST = 2 * MAXN;

	std::string s1, s2;
	std::cin >> s1 >> s2;

	int dist[MAXN + 1][MAXN + 1];

	for (int i = 0; i <= s1.size(); ++i) {
		for (int j = 0; j <= s2.size(); ++j)
		{
			if (i == 0 && j == 0) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = MAXDIST;
			if (i > 0)
				dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
			if (j > 0)
				dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
			if (i && j)
				dist[i][j] = std::min(dist[i][j], dist[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
		}
	}

	std::cout << dist[s1.size()][s2.size()] << '\n';
	return 0;
}
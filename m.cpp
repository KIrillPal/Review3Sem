#include <iostream>
#include <vector>
#include <string>

#define MAXN 1000
#define MAXDIST 2000

inline void relaxDp(int i, int j, int dist[MAXN + 1][MAXN + 1], bool add_char_flag) {
	dist[i][j] = MAXDIST;
	if (i > 0)
		dist[i][j] = std::min(dist[i][j], dist[i - 1][j] + 1);
	if (j > 0)
		dist[i][j] = std::min(dist[i][j], dist[i][j - 1] + 1);
	if (i && j)
		dist[i][j] = std::min(dist[i][j], dist[i - 1][j - 1] + add_char_flag);
}

int solve(const std::string& s1, const std::string& s2) {

	int dist[MAXN + 1][MAXN + 1];

	for (int i = 0; i <= s1.size(); ++i) {
		for (int j = 0; j <= s2.size(); ++j)
		{
			if (i == 0 && j == 0) {
				dist[i][j] = 0;
				continue;
			}
			int add_char_flag = (i && j) ? s1[i-1] != s2[j-1] : 0;
			relaxDp(i, j, dist, add_char_flag);
		}
	}

	return dist[s1.size()][s2.size()];
}

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << solve(s1, s2) << '\n';
	return 0;
}
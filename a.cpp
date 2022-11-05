#include <iostream>
#include <algorithm>
#include <vector>

int grasshopper(int n, int m) {
	std::vector<int> cnts(n + 1);
	cnts[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0 && i - j <= m; --j) {
			cnts[i] += cnts[j];
		}
	}
	return cnts[n];
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::cout << grasshopper(n, m) << '\n';
	return 0;
}
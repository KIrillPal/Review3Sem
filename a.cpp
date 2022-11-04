#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> cnts(n + 1);
	cnts[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0 && i - j <= m; --j) {
			cnts[i] += cnts[j];
		}
	}
	cout << cnts[n] << '\n';
	return 0;
}
﻿#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
	std::string a, b;
	std::cin >> a >> b;
	int a_size = a.size();
	int b_size = b.size();
	int best_li = 0, best_ri = 0, best_di = 0;

	std::vector<int> old_dp(b_size + 1);
	std::vector<int> new_dp(b_size + 1);
	for (int i = 1; i <= a_size; ++i) {

		for (int j = 1; j <= b_size; ++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				new_dp[j] = old_dp[j - 1] + 1;
				if (best_di < new_dp[j]) {
					best_di = new_dp[j];
					best_li = j - best_di;
					best_ri = j;
				}
				else if (best_di == new_dp[j]) {
					int li = j - best_di;
					for (int k = 0; k < best_di; ++k) {
						if (b[best_li + k] > b[li + k]) {
							best_li = li;
							best_ri = j;
							break;
						}
						else if (b[best_li + k] < b[li + k])
							break;
					}
				}
			}
			else new_dp[j] = 0;
		}
		old_dp.swap(new_dp);
	}

	std::cout << b.substr(best_li, best_di) << '\n';
	return 0;
}
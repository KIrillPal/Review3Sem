﻿#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void relaxSeg(int j, int& best_li, int& best_ri, int& best_di, const std::string& b) {
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

std::string solve(const std::string& a, const std::string& b) {
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
					relaxSeg(j, best_li, best_ri, best_di, b);					
				}
			}
			else new_dp[j] = 0;
		}
		old_dp.swap(new_dp);
	}

	return b.substr(best_li, best_di);
}

int main()
{
	std::string a, b;
	std::cin >> a >> b;
	std::cout << solve(a, b) << '\n';
	return 0;
}
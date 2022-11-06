#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

typedef unsigned long long ull;

struct LLong {
	const ull DATA_PART = 0x00000000FFFFFFFF;
	const ull DATA_SHIFT = 32;
	std::vector<unsigned> data;

	LLong() {};

	LLong(unsigned value)
	{
		if (value)
			data.push_back(value);
	}

	LLong(const LLong& value)
	{
		data.resize(value.data.size());
		for (int i = 0; i < data.size(); ++i) {
			data[i] = value.data[i];
		}
	}

	LLong& operator = (unsigned value)
	{
		data.clear();
		if (value)
			data.push_back(value);
		return *this;
	}

	void shift_up(int nceils) {
		data.resize(data.size() + nceils);
		for (int i = data.size() - 1; i >= 0; --i) {
			data[i] = (i >= nceils ? data[i - nceils] : 0);
		}
	}

	LLong& operator *= (unsigned second)
	{
		ull mod = 0;
		for (int i = 0; i < data.size(); ++i) {
			mod = 1ULL * data[i] * second + mod;
			data[i] = mod & DATA_PART;
			mod >>= DATA_SHIFT;
		}

		if (mod > 0)
			data.push_back(mod);
		return *this;
	}

	LLong& operator += (const LLong & second)
	{
		if (data.size() < second.data.size()) {
			data.resize(second.data.size());
		}

		ull sum = 0;
		for (int i = 0; i < second.data.size(); ++i)
		{
			sum += 0ULL + data[i] + second.data[i];
			data[i] = sum & DATA_PART;
			sum >>= DATA_SHIFT;
		}

		if (sum > 0) {
			if (data.size() > second.data.size())
				data[second.data.size()] += sum;
			else data.push_back(sum);
		}
		return *this;
	}

	unsigned get_digit(unsigned base)
	{
		ull mod = 0;
		for (int i = data.size() - 1; i >= 0; --i)
		{
			ull cell = data[i] + (mod << DATA_SHIFT);
			mod = cell % base;
			data[i] = cell / base;
		}

		if (data.back() == 0)
			data.pop_back();

		return mod;
	}

	LLong square() {
		LLong sq_value;
		for (int i = 0; i < data.size(); ++i) {
			LLong tmp = *this;
			tmp *= data[i];
			tmp.shift_up(i);
			sq_value += tmp;
		}
		return sq_value;
	}
};

void fillDp(int n, int m, std::vector<std::vector<LLong> >& combs) {
	for (int len = 1; len <= n; ++len) {
		for (int sum = 0; sum <= len * (m - 1); ++sum) {
			for (int k = 0; k < m; ++k) {
				if (sum >= k)
					combs[len][sum] += combs[len - 1][sum - k];
			}
		}
	}
}

LLong getTicketCount(int n, int m) {
	std::vector<std::vector<LLong> > combs(n + 1, std::vector<LLong>(n * (m - 1) + 1));
	combs[0][0] = 1;

	fillDp(n, m, combs);

	LLong sqs_sum = 0;
	for (int s = 0; s <= n * (m - 1); ++s) {
		sqs_sum += combs[n][s].square();
	}
	return sqs_sum;
}

void coutLLong(LLong& value) {
	std::vector<char> digits;
	while (!value.data.empty()) {
		digits.push_back(value.get_digit(10) + '0');
	}

	while (!digits.empty()) {
		std::cout << digits.back();
		digits.pop_back();
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	n /= 2;

	LLong sqs_sum = getTicketCount(n, m);
	coutLLong(sqs_sum);
	std::cout << '\n';
	return 0;
}

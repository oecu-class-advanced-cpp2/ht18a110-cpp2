#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //’Tõ‚·‚é’l‚ÌãŒÀ’lB

//‘f”‚©‘f”‚Å‚È‚¢‚©
bool is_prime(int num) {
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i < num - 1; i++) {
		if (num%i == 0) 
			return false;
		return true;
	}
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int current = a;
	int count = 0;
	while (current <= CPP2_PRIME_UPPER_LIMIT) {
		if (is_prime(current)) {
			count++;
			if (count == n)
				return current;
		}
		current += d;
	}
	return(-1);
}
int main() {
	std::cout << "(367, 186, 151)" << nth_prime(367, 186, 151) << std::endl;
	std::cout << "(179, 10, 203)" << nth_prime(179, 10, 203) << std::endl;
	std::cout << "(271, 37, 39)" << nth_prime(271, 37, 39) << std::endl;
	std::cout << "(103, 230, 1)" << nth_prime(103, 230, 1) << std::endl;
	std::cout << "(27, 104, 185)" << nth_prime(27, 104, 185) << std::endl;
	std::cout << "(253, 50, 85)" << nth_prime(253, 50, 85) << std::endl;
	std::cout << "(1, 1, 1)" << nth_prime(1, 1, 1) << std::endl;
	std::cout << "(9075, 337, 210)" << nth_prime(9075, 337, 210) << std::endl;
	std::cout << "(307, 24, 79)" << nth_prime(307, 24, 79) << std::endl;
	std::cout << "(331, 221, 177)" << nth_prime(331, 221, 177) << std::endl;
	std::cout << "(259, 170, 40)" << nth_prime(259, 170, 40) << std::endl;
	std::cout << "(269, 58, 102)" << nth_prime(269, 58, 102) << std::endl;

	return 0;
}
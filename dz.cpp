#include <iostream>
#include <chrono>
#include <set>
#include <string>
#include "Nedelko_group.h"
#include "Paisev.h"
#include "Fedorov.h"
#include "Kuvshinov.h"
#include "Bursak.h"


#define TEST(x) testFunc(x, #x)

long long Run(bool f(int), const int numbers) {
	std::set<int> prime_Numbers;
	auto start = std::chrono::system_clock::now();
	for (int i = 1; i <= numbers; i++) {
		if (f(i))
			prime_Numbers.insert(i);
	}
	auto stop = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	return time;
}

long long Run(std::vector<int> f(int), const int numbers) {
	std::set<int> prime_Numbers;
	auto start = std::chrono::system_clock::now();
	f(numbers);
	auto stop = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	return time;
}

template <typename type>
void testFunc(type f(int), const std::string functionName) {
	std::cout << "Function name: " << functionName << std::endl;
	for (int i = 100; i <= 100000000; i = i * 100) {
		std::cout << "For numbers " << i << std::endl;
		std::cout << "Time: " << Run(f,i) << std::endl;
	}
}

int main() {
	TEST(sieveOfAtkin);
	TEST(sieveOfEratosthenes);
	TEST(method_6k_1);
	TEST(TrialDivision);
	TEST(Sundaram);
}
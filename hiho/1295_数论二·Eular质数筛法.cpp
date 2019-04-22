#include <iostream>

using namespace std;

// Eular质数筛法
// (目的是减少枚举次数)
int main() {
	int n;
	cin >> n;
	//初始化数筛
	bool * isPrime = new bool[n + 1];
	fill(isPrime, isPrime + (n + 1), true);
	//质数表
	int * primeList = new int[n + 1]();
	
	int primeCount = 0;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primeCount++;
			primeList[primeCount] = i;
		}
		for (int j = 1; j <= primeCount; j++) {
			if (i*primeList[j] > n) {
				break;
			}
			isPrime[i*primeList[j]] = false;
			if (i%primeList[j] == 0) {
				break;
			}
		}
	}

	cout << primeCount << endl;
	system("pause");
	return 0;
}

/*
// Eratosthenes筛法(初版)
int main() {
	int n;
	cin >> n;
	//初始化数筛
	bool * isPrime = new bool[n + 1];
	fill(isPrime, isPrime + (n + 1), true);
	
	int primeCount = 0;

	for (int i = 2; i <= n; i++) {
		int multiple = 2;
		while (i*multiple <= n) {
			isPrime[i*multiple] = false;
			multiple++;
		}
	}
	
	for (int i = 2; i <= n; i++) {	//可优化
		if (isPrime[i]) {
			primeCount++;
		}
	}
	cout << primeCount << endl;
	system("pause");
	return 0;
}
*/
/*
// 优化
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primeCount++;
			int multiple = 2;
			while (i*multiple <= n) {
				isPrime[i*multiple] = false;
				multiple++;
			}
		}
	}
*/

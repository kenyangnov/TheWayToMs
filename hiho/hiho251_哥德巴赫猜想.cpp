#include <iostream>
#include <set>
#include <algorithm>   

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
	int *primeList = new int[n+1];
	//质数集合
	set<int> primeSet;

	int primeCount = 0;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primeCount++;
			primeList[primeCount] = i;
			primeSet.insert(i);
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
	

	set<int>::const_iterator target;
	for (int i = 1; i <= primeCount; i++) {
		if (primeSet.find(n - primeList[i]) != primeSet.end()) {
			cout << primeList[i] << " " << (n - primeList[i]) << endl;
			break;
		}
	}
	/*
	set<int>::const_iterator b = primeSet.begin();
	for (; b != primeSet.end(); b++)
	{
		cout << *b << endl;
	}
	system("pause");
	*/
	return 0;
}


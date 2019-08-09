#include <iostream>
#include <map>
using namespace std;

//暴力求解
int Func1(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1 || n == 2) {
		return n;
	}
	else {
		return Func1(n - 1) + Func1(n - 2);
	}
}

//hash表，空间换时间
map<int, int> m;
int Func2(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 2) {
		return n;
	}
	else {
		if (m.count(n) > 0) {	//如果之前已经计算过直接返回
			return m[n];
		}
		else {
			int ans = Func2(n - 1) + Func2(n - 2);
			m[n] = ans;
			return ans;
		}
	}
}

//斐波那契求解
int Func3(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n <= 2) {
		return n;
	}
	int a = 1, b = 2, sum = 0;
	for (int i = 3; i <= n; i++) {
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	//cout << Func1(n);
	//cout << Func2(n);
	cout << Func3(n);
	system("pause");
	return 0;
}
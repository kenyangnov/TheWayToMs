#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	//多数时候，刷题时不必申请动态数组，根据数据规模申请相应静态数组
	int a[1000];

	//记录a中不同金币的数量
	unordered_map<int, int> h;
	for (int i = 0; i<n ; i++) {
		cin >> a[i];
		h[a[i]]++;
		//输入一个记录一个
	}

	//记录不同金币数的组合
	unordered_map<int, int> f;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1 ; j < n; j++) {	//注：j=i+1，j=i是错的
			f[a[i] + a[j]]++;
		}
	}

	long long ans = 0;
	//容斥原理
	for (int i = 0; i < n; i++) {
		for (int j = i + 1 ; j < n; j++) {	//注：j=i+1
			if (a[i] == a[j]) {
				ans += f[a[i] + a[j]] - ((h[a[i]] - 1) + (h[a[j]] - 1) - 1);
			}
			else {
				ans += f[a[i] + a[j]] - h[a[i]] - h[a[j]] + 1;
			}
		}
	}
	cout << ans << endl;
	system("pause");
	return 0;
}

/*
举例：
情况1：假设小Hi为下标 1, 3
	A[10, 10, 20, 20, 20]
	i   j   为下标
	1   3
	1   4
	1   5
	2   3
//  2   4     选这两种(去掉 3+2-1 / h[20]+h[10]-1 种)
//  2   5
	
情况2：假设小Hi为下标 1, 2
	A[20, 20, 20, 20, 20]
	i   j
	1   2
	1   3
	1   4
	1   5
	2   3
	2   4
	2   5
//  3   4     选这三种(去掉 (5-1)+(5-1)-1 / (h[20]-1)+(h[20]-1)-1 种)
//  3   5
//  4   5
*/
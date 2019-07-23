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
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2e9;
const int maxn = 100000 + 10;

int m, n, l;
int a[maxn], b[maxn], c[maxn];

int main() {
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= l; i++) cin >> c[i];
	//首先排序
	sort(b + 1, b + 1 + m);
	sort(c + 1, c + 1 + l);
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		// 身高大于等于A[i]的最矮的人为：B[j+1]和C[k+1]，身高小于等于Ai的最高的人：B[j]和C[k]
		// 注:lower_bound函数返回从first开始的第一个大于或等于val的元素的地址（数组必须是排好序的数组）
		int j = lower_bound(b + 1, b + 1 + m, a[i]) - (b + 1); //相对于(b+1)的偏移量,即身高小于等于Ai的最高的人
		int k = lower_bound(c + 1, c + 1 + l, a[i]) - (c + 1);
		if(j>0 && k>0) ans = min(ans, abs(a[i] - b[j]) + abs(a[i] - c[k]) + abs(b[j] - c[k]));
		if (k > 0)  ans = min(ans, abs(a[i] - b[j + 1]) + abs(a[i] - c[k]) + abs(b[j + 1] - c[k]));
		if (j > 0)  ans = min(ans, abs(a[i] - b[j]) + abs(a[i] - c[k + 1]) + abs(b[j] - c[k + 1]));
		ans = min(ans, abs(a[i] - b[j + 1]) + abs(a[i] - c[k + 1]) + abs(b[j + 1] - c[k + 1]));
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
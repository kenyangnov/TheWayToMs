#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2e9;
const int maxn = 100000 + 10;

int m, n, l;
int a[maxn], b[maxn], c[maxn];

int main() {
	cin >> n >> m >> l;
	for (int i = 0; i <= n - 1; i++) cin >> a[i];
	for (int i = 0; i <= m - 1; i++) cin >> b[i];
	for (int i = 0; i <= l - 1; i++) cin >> c[i];
	//首先排序
	sort(b, b + m);
	sort(c, c + l);
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		// 在B、C中找到身高大于等于A[i]的最矮的人，身高小于Ai的最高的人
		// 注:lower_bound函数返回从first开始的第一个大于或等于val的元素的地址（数组必须是排好序的数组）
		int j = lower_bound(b, b + m, a[i]) - b; //大于或等于A[i]的最矮的人(若存在)/小于A[i]最高的人
		int k = lower_bound(c, c + l, a[i]) - c;

		ans = min(ans, abs(a[i] - b[j]) + abs(a[i] - c[k]) + abs(b[j] - c[k]));	//B、C中都取大于A最低的
		if ((j - 1) >= 0)ans = min(ans, abs(a[i] - b[j - 1]) + abs(a[i] - c[k]) + abs(b[j - 1] - c[k]));	//B取小于A最高的，C取大于A最低的
		if ((k - 1) >= 0)ans = min(ans, abs(a[i] - b[j]) + abs(a[i] - c[k - 1]) + abs(b[j] - c[k - 1]));	//B取大于A最低的，C取小于A最高的
		if ((j - 1) >= 0 && (k - 1) >= 0)ans = min(ans, abs(a[i] - b[j - 1]) + abs(a[i] - c[k - 1]) + abs(b[j - 1] - c[k - 1]));	//B、C都取大于A最高的
	}
	cout << ans << endl;
	return 0;
}
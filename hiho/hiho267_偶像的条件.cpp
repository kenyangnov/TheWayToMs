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

	sort(b + 1, b + 1 + m);
	sort(c + 1, c + 1 + l);
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		
	}
	cout << ans << endl;

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
const int N = 1000 + 10;
double dp[N][N], p[N];

int main() {
	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}

	dp[1][0] = (1.0 - p[1]);
	dp[1][1] = p[1];
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - p[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
			}
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}
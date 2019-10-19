#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int main() {
	int n;
	cin >> n;
	int maxn = n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == maxn) {
			maxn--;
		}
	}
	cout << maxn << endl;
	return 0;
}

// 首先认真读题中条件：第二行包含N个两两不同整数A1, A2, ... AN。(1 <= Ai <= N)

// 网上解析：https://blog.csdn.net/Sirius_han/article/details/77945934
// 如果每个数都移动，N个数最多移动N次就形成一个递增序列；
// 如果最后一个数是最大的就不需要移动，第N-1个是倒数第二大的也不需要动，
// 只有当第i个数不是i时才移动；

// hiho解析：
//我们假设从A1, A2, ... //AN从挑选了K个数，把他们放到最左边之后可以使得序列是递增排列的。
//那么被挑选的这K个数一定是在新数列的前K个，而未被挑选的N-K个数一定是按照原顺序留在新数列的最后N-K个。
//又因为新数列是递增的，所以未被挑选的N-K个数在原序列中一定是K+1, K+2, K+3, ... N。并且是按顺序排列的。
//我们现在要K最小，也就找到最小的K，满足K+1, K+2, ... N在原序列中是按从左到右排列的。
//于是直接贪心找出K即可。
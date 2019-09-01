#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, m, q;
int pre[maxn];
int score[maxn];

//变量初始化可以统一在init函数中完成
void init() {
	for (int i = 0; i <= n; i++) pre[i] = i;
	//根节点记为0分
	memset(score, 0, sizeof(score));
}

int find(int x) {
	//找到根节点
	int r = x;
	while (pre[r] != r) {
		r = pre[r];
	}
	//压缩路径
	int i = x, j, k;
	while (i != r)
	{
		j = pre[i];
		pre[i] = r;
		k = pre[i];
		while (k != r) {
			score[i] += score[k];
			k = pre[k];
		}
		i = j;
	}
	return r;
}

void join(int x, int y, int value) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	else {
		//以后者(y)为前驱节点
		pre[fx] = fy;
		score[fx] = value - score[x] + score[y];
	}
	return;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	cin >> n >> m >> q;
	init();
	int x, y, value;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> value;
		join(x, y, value);
		/*
		for (int j = 0; j < n; j++) {
			cout << pre[j] << " ";
		}
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << score[j] << " ";
		}
		cout << endl;
		*/
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cout << (same(x, y) ? score[x] - score[y] : -1) << endl;
	}
	system("pause");
	return 0;
}

/*
方程组：
x - fx = sx
y - fy = sy		===>> fx - fy = value - sx + sy 
x - y = value
（注：做减法时，谁是减数就是求与谁的相对值，以y为根就要求与y的相对值）
*/

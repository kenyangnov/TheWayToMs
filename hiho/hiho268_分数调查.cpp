//参考：https://blog.csdn.net/liujian20150808/article/details/50848646
//参考：https://blog.csdn.net/qq_37685156/article/details/80565784

#include <iostream>
#include <memory.h>
using namespace std;

int n, m, q;
const int maxn = 1e5 + 1;
int score[maxn];	//score[i]表示i到i的父结点的距离，即i的父结点比i高的分数
int parent[maxn];

void init() {
	for (int i = 0; i <= n; i++) parent[i] = i;
	memset(score, 0, sizeof(score));
}

int find(int x) {
	if (parent[x] != x) {
		int tmp = parent[x];
		parent[x] = find(parent[x]);
		score[x] += score[tmp];
	}
	return parent[x];
}

void unit(int x, int y, int v) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) {
		return;
	}
	else {
		parent[fx] = fy;
		score[fx] = score[y] - score[x] - v;
	}
	return;
}
bool same(int x, int y) {
	return find(x) == find(y);
}


int main() {
	cin >> n >> m >> q;
	init();
	int x, y, v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> v;
		unit(x, y, v);
	}
	for (int j = 0; j < q; j++) {
		cin >> x >> y;
		cout << (same(x, y) ? score[y] - score[x] : -1) << endl;
	}
	system("pause");
	return 0;
}
/*
方程组：
fx - x = sx
fy - y = sy		===>> fy - fx = sy - sx - value 
x - y = value
*/
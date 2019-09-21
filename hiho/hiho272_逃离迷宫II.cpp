#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
//BFS+贪心
//BFS每一步能到达当前能走到的所有点，因此每一步走到的位置用的都是最短步数
int n, m;
char map[501][501] = { 0 };
bool visit[501][501] = { 0 };
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int res;	
struct node
{
	int i;
	int j;
	int cnt;
	node() {};
	node(int x, int y, int z) :i(x), j(y), cnt(z) {};
};
queue < node> q;

int findway(node s) {
	visit[s.i][s.j] = true;	//已访问
	q.push(s);

	while (!q.empty()) {
		//出栈
		node f = q.front();
		q.pop();
		//找到可达点并入栈
		for (int i = 0; i < 4; i++) {
			int nexti = f.i + dir[i][0];
			int nextj = f.j + dir[i][1];
			while (map[nexti][nextj] != '#' && nexti >= 0 && nexti < n && nextj >= 0 && nextj < m) {
				if (map[nexti][nextj] == 'T') {
					return f.cnt + 1;
				}
				nexti += dir[i][0];
				nextj += dir[i][1];
			}
			//遇到墙或边界，回退一步
			nexti -= dir[i][0];
			nextj -= dir[i][1];
			if (visit[nexti][nextj] == false){ //保证之前未访问过（剪枝）
				node nextnode = node(nexti, nextj, f.cnt + 1);
				visit[nexti][nextj] = true;	//已访问
				q.push(nextnode);
			}
		}
	}
	return -1;
}

int main() {
	memset(map, '0', sizeof(map));
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	node s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				visit[i][j] = true;
				s.i = i;
				s.j = j;
				s.cnt = -1;
			}
		}
	}
	cout << findway(s) << endl;
	return 0;
}
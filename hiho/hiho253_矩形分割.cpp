#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXM = 100 + 2;
const int MAXL = MAXM * 3;
//dy��dx�����ϡ��ҡ��¡����ĸ�����
const int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
int N, M;
bool maze[MAXL][MAXL];

inline bool in(int y, int x) {
	return y >= 0 && y < 3 * N && x >= 0 && x < 3 * M;
}

void dfs(int y, int x){
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i], nx = x + dx[i];
		if (in(ny, nx) && !maze[ny][nx]){
			maze[ny][nx] = true;
			
			dfs(ny, nx);
		}
	}
}

int main() {
	// int N, M;	//ǰ���Ѿ�������ȫ�ֱ���
	cin >> N >> M;
	//cout << in(1, 1) << endl;
	//��ջ������еĻ��з�
	cin.clear();
	cin.ignore();
	//��ʼ��maze
	memset(maze, 0, sizeof(maze));
	//�������
	string* s = new string[N];
	for (int i = 0; i < N; i++) {
		getline(cin, s[i]);
		for (int j = 0; j < M; j++)
		{
			if (s[i][j] == '\\') {
				maze[i * 3][j * 3] = maze[i * 3 + 1][j * 3 + 1] = maze[i * 3 + 2][j * 3 + 2] = true;
			}
			if (s[i][j] == '/') 
			{
				maze[i * 3][j * 3 + 2] = maze[i * 3 + 1][j * 3 + 1] = maze[i * 3 + 2][j * 3] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N * 3; i++) {
		for (int j = 0; j < M * 3; j++) {
			// cout << maze[i][j] << ' ';
			if (!maze[i][j]) {
				ans++;
				maze[i][j] = true;
				dfs(i, j);
			}
		}
		// cout << endl;
	}
	cout << ans << endl;
	cin.get();
	return 0;
}
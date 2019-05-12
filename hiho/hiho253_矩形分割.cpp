//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <map>
//#include <stack>
//using namespace std;
//#define INF 0x3f3f3f3f
//#define LL long long
//#define fi first
//#define se second
//#define mem(a,b) memset((a),(b),sizeof(a))
//
//const int MAXN = 100 + 2;
//const int MAXL = MAXN * 3;
//const int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
//int N, M;
//bool maze[MAXL][MAXL];
//
//inline bool in(int y, int x)
//{
//	return y >= 0 && y < 3 * N && x >= 0 && x < 3 * M;
//}
//
//void dfs(int y, int x)
//{
//	for (int i = 0; i < 4; ++i)
//	{
//		int ny = y + dy[i], nx = x + dx[i];
//		if (in(ny, nx) && !maze[ny][nx])
//		{
//			maze[ny][nx] = true;
//			dfs(ny, nx);
//		}
//	}
//}
//
//int main()
//{
//	while (~scanf_s("%d %d", &N, &M))
//	{
//		getchar();
//		mem(maze, 0);
//		for (int i = 0; i < N; ++i)
//		{
//			char s[MAXN];
//			gets_s(s);
//			for (int j = 0; j < M; ++j)//拆点
//			{
//				if (s[j] == '\\')
//					maze[i * 3][j * 3] = maze[i * 3 + 1][j * 3 + 1] = maze[i * 3 + 2][j * 3 + 2] = true;
//				if (s[j] == '/')
//					maze[i * 3][j * 3 + 2] = maze[i * 3 + 1][j * 3 + 1] = maze[i * 3 + 2][j * 3] = true;
//			}
//		}
//		int ans = 0;
//		for (int i = 0; i < N * 3; ++i) {
//			for (int j = 0; j < M * 3; ++j) {
//				cout << maze[i][j] << ' ';
//				if (!maze[i][j])
//				{
//					++ans;
//					maze[i][j] = true;
//					dfs(i, j);
//				}
//			}
//			cout << endl;
//		}	
//		printf("%d\n", ans);
//	}
//
//
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

const int MAXM = 100 + 2;
const int MAXL = MAXM * 3;
//dy和dx构成上、右、下、左四个方向
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
	int N, M;
	cin >> N >> M;

	//清空缓冲区中的换行符
	cin.clear();
	cin.ignore();
	//初始化maze
	memset(maze, 0, sizeof(maze));
	//读入符号
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
			cout << maze[i][j] << ' ';
			if (!maze[i][j]) {
				ans++;
				maze[i][j] = true;
				dfs(i, j);
			}
		}
		cout << endl;
	}
	cout << ans << endl;
	cin.get();
	return 0;
}

/*
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

// 每个单元中的四个子区域
struct Ceil {
	int top;
	int right;
	int down;
	int left;
};

//将符号转换为区域编号
void CeilPattern(char c, Ceil *ceil){
	Ceil pattern = { 0, 0, 0, 0};
	switch (c)
	{
	case '\\':
		pattern = { 1, 1, 2, 2 };
		break;
	case '/':
		pattern = { 1, 2, 2, 1 };
		break;
	case ' ':
		pattern = { 1, 1, 1, 1 };
		break;
	default:
		break;
	}
	*ceil = pattern;
}

void DisplayCeil(Ceil* ceil) {
	cout << ceil->top << ceil->right << ceil->down << ceil->left << endl;
}


int main() {
	int m, n;
	cin >> m >> n;
	
	//清空缓冲区中的换行符
	cin.clear();
	cin.ignore();

	//读入符号
	string *s = new string[m];
	for (int i = 0; i < m; i++) {
		getline(cin, s[i]);
	}

	//初始化ceils
	Ceil **line = new Ceil*[m];
	for (int i = 0; i < m; i++) {
		line[i] = new Ceil[n];
	}
	
	//给ceils单元赋值
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			CeilPattern(s[i][j], &line[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			DisplayCeil(&line[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] line[i];
	}
	delete[] line;

	cin.get();
	return 0;
}
*/
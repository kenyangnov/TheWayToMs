#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;
vector<pair<int, int>> vp[MAXN];	//按照特定格式存储读入数据:{child,(parent,index)}
int vx[MAXN];
int vy[MAXN];
/*
输入为(1,2),(1,3),(1,3)，那么vx和vy为：
	vx		vy
	1		2
	1		3
	1		3
*/
vector<int> G[MAXN];	//图结构(临时构建，重复使用)
// vector<vector <int> > G(MAXN, vector<int>(MAXN));

int n; //记录节点数
int cnt; //记录DFS遍历的节点数

void DFS(int pos) {	//只在本题树结构适用的DFS，不需要visited标记
	cnt++;
	for (int i = 0; i < G[pos].size(); i++) {
		DFS(G[pos][i]);
	}
}

int Remove(int parent, int child, int n)	//判断移除(p,c)后,原图是否还是树
{
	//初始化
	for (int i = 0; i <= n; i++)
		G[i].clear();
	int flag = 0;	//标记边是否被移除

	//建图 
	for (int i = 1; i <= n; i++){
		if (vx[i] == parent && vy[i] == child){
			if (flag == 1){	//跳过
				G[vx[i]].push_back(vy[i]);
			}
			flag = 1;
		}
		else{
			G[vx[i]].push_back(vy[i]);
		}
	}

	//用前更新
	cnt = 0;

	//建完图后判断这个图是否符合题目要求
	int root = 1;
	DFS(root);
	return cnt == n; //符合题目要求的条件就是能够遍历所有节点 
}


int main() {
	//初始化图
	cin >> n;
	int parent, child;	//父节点和子节点
	for (int i = 1; i <= n; i++) {
		cin >> parent >> child;
		vp[child].push_back(make_pair(parent, i)); //记录点对以及读取的行号
		vx[i] = parent;
		vy[i] = child;
	}
	
	if (vp[1].size() != 0) {	//如果头节点有父节点，说明对应行数据是可疑的
		cout << vp[1][0].second << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (vp[i].size() > 1) {	//说明有两个父节点,判断移除其中一个父节点后是否满足要求
				vector<int> ans;
				if (Remove(vp[i][0].first, i, n)) {
					ans.push_back(vp[i][0].second);
				}
				if (Remove(vp[i][1].first, i, n)) {
					ans.push_back(vp[i][1].second);
				}
				for (int j = 0; j < ans.size(); j++) {
					cout << ans[j] << ' ';
				}
			}
		}
	}
	return 0;
}

/*
注意：
题中已说明：“其中1号节点是整棵树的根”
题中已说明：“第一行包含一个整数N，表示树的节点数目。
			以下N行每行两个整数a和b，表示a是b的父节点。 ”
障碍：
1.如何动态开辟二维数组，来实现图结构: 使用vector（两种写法）
2.如何确定存储树结构的图的大小: 使用题中所给的最大值
3.如何记录读取数据的行号：使用pair结构记录数据和行号
4.如何判断图(vector结构实现)删除一个节点后是否为树：重新建图后，再判断是否能按照指定规则遍历完整张图
5.全局变量使用时候，一定要注意不要在局部重复定义
*/

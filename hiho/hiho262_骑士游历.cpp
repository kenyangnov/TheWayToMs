#include <iostream>
#include <string.h>
using namespace std;

long long grid[64][64];
long long res[64][64];
long long m = 1000000007;
long long n, r, c;

//初始化变换矩阵grid
//用于表示两点之间是否可达(8*8棋盘->64*64两点关系)
//方向：int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{1,-2},{1,2},{2,1}};
void initGrid()
{
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			int index = (i - 1) * 8 + j - 1;
			if (j + 2 <= 8 && i + 1 <= 8) {
				int temp = i * 8 + j + 1;
				grid[index][temp] = 1;
			}
			if (j + 1 <= 8 && i + 2 <= 8) {
				int temp = (i + 1) * 8 + j;
				grid[index][temp] = 1;
			}
			if (j + 2 <= 8 && i - 1 >= 1) {
				int temp = (i - 2) * 8 + j + 1;
				grid[index][temp] = 1;
			}
			if (j + 1 <= 8 && i - 2 >= 1) {
				int temp = (i - 3) * 8 + j;
				grid[index][temp] = 1;
			}
			if (j - 1 >= 1 && i - 2 >= 1) {
				int temp = (i - 3) * 8 + j - 2;
				grid[index][temp] = 1;
			}
			if (j - 2 >= 1 && i - 1 >= 1) {
				int temp = (i - 2) * 8 + j - 3;
				grid[index][temp] = 1;
			}
			if (j - 1 >= 1 && i + 2 <= 8) {
				int temp = (i + 1) * 8 + j - 2;
				grid[index][temp] = 1;
			}
			if (j - 2 >= 1 && i + 1 <= 8) {
				int temp = i * 8 + j - 3;
				grid[index][temp] = 1;
			}
		}
	}
} 

void mul1() // res * grid
{
	long long temp[64][64];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			for (int k = 0; k < 64; k++) {
				temp[i][j] += res[i][k] * grid[k][j];
				temp[i][j] %= m;	//取模防止溢出
			}
		}
	}
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			res[i][j] = temp[i][j];
		}
	}
}

void mul2() // grid * grid（即更新base）
{
	long long temp[64][64];
	memset(temp, 0, sizeof(temp));
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			for (int k = 0; k < 64; k++) {
				temp[i][j] += grid[i][k] * grid[k][j];
				temp[i][j] %= m;
			}
		}
	}
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			grid[i][j] = temp[i][j];
		}
	}
}

void Factor(long long n)
{
	//初始化结果矩阵
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			if (i == j) {
				res[i][j] = 1;
			}
			else
			{
				res[i][j] = 0;
			}
		}
	}
	//矩阵快速幂
	while (n) {
		if (n & 1) {
			mul1();
		}
		mul2();
		n >>= 1;
	}

}

int main(int argc, const char* argv[]) {
	memset(grid, 0, sizeof(grid));
	initGrid();
	cin >> n >> r >> c;
	Factor(n);
	long long ans = 0;
	long long index = (r - 1) * 8 + c - 1;
	//通过计算index列的和，统计走法的总数
	for (int i = 0; i < 64; i++) {
		ans += res[index][i];
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}


//快速幂(二进制的作用是标记，决定基数要不要乘进ans)
int poww(int a, int b) {
	int ans = 1, base = a; 
	while (b != 0) {
		if (b & 1) {
			ans *= base;
		}
		base *= base;
		b >>= 1;
	}
	return base;
}

//矩阵快速幂，用于求解递推式
//可以在O(logn)复杂度下计算出斐波那契数列第n项
//关系矩阵为{1, 1; 1, 0}
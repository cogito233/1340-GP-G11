#include "map.h"
#include <bits/stdc++.h>
namespace mp{
	void map::dfs(int x, int y, int colour, int &sum) {
		this->f[x][y] = 0;
		sum += 1;
		if (this->f[x-1][y] == colour)
			this->dfs(x-1, y, colour, sum);
		if (this->f[x+1][y] == colour)
			this->dfs(x+1, y, colour, sum);
		if (this->f[x][y-1] == colour)
			this->dfs(x, y-1, colour, sum);
		if (this->f[x][y+1] == colour)
			this->dfs(x, y+1, colour, sum);
	}
	void map::copy_column(int x,int y) {
		if (x == y) return;
		for (int i = 1; i <= 20; i++)
			this->f[x][i] = this->f[y][i];
	}
	void map::normalization(){
		for (int j = 1; j <= 20; j++) {
			int k = 21;
			for (int i = 1; i <= 20; i++) 
				if (this->f[i][j])
					this->f[--k][j] = this->f[i][j];
			for (k--; k >= 1; k--) this->f[k][j] = 0;
		}
		int k = 0;
		for (int i = 1; i <= 20; i++) 
			if (this->f[i][1])
				this->copy_column(++k,i);
		for (k++; k <= 20; k++) this->copy_column(k,0);
	}
	
	map::map() {
		srand(time(0));
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				this->f[i][j] = rand() % 3 + 1;
	}
	
	int map::map_query(int x,int y) {
		return this->f[x][y];
	}
	
	bool map::is_end() {
		bool flag = 1;
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				flag = flag && !(this->f[i][j] == this->f[i][j-1] || this->f[i][j] == this->f[i-1][j]);
		return flag;
	}
	
	int map::operation(int x, int y) {
		if (this->f[x][y] == 0) return -1;
		if (!(this->f[x][y] == this->f[x][y-1] || this->f[x][y] == this->f[x-1][y]
			|| this->f[x][y] == this->f[x+1][y] || this->f[x][y] == this->f[x][y+1])) return -1;
		int sum = 0;
		this->dfs(x, y, this->f[x][y], sum);
		this->normalization();	
		return sum * sum * 5;
	}
	
	int map::reward_score() {
		int sum=1000;
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				if (this->f[i][j]) sum-=100;
		return sum<0 ? 0 : sum;
	}
}

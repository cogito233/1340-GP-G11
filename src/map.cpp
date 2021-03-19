#include <map.h>

namespace map{
	void map::dfs(int x, int y, int colour, int &sum) {
		this->map[x][y] = 0;
		sum += 1;
		if (this->map[x-1][y] == colour)
			this->dfs(x-1, y, colour, sum);
		if (this->map[x+1][y] == colour)
			this->dfs(x+1, y, colour, sum);
		if (this->map[x][y-1] == colour)
			this->dfs(x, y-1, colour, sum);
		if (this->map[x][y+1] == colour)
			this->dfs(x, y+1, colour, sum);
	}
	void map::copy_column(int x,int y) {
		if (x == y) return;
		for (int i = 1; i <= 20; i++)
			this->map[x][i] = this->map[y][i];
	}
	void map::normalization(){
		for (int i = 1; i <= 20 ;i++) {
			int k = 0;
			for (int j = 1; j <= 20; j++) 
				if (this->map[i][j])
					this->map[i][++k] = this->map[i][j];
			for (k++; k <= 20; k++) this->map[i][k] = 0;
		}
		int k = 0;
		for (int i = 1; i <= 20; i++) 
			if (this->map[i][1])
				this->copy_column(++k,i);
		for (k++; k <= 20; k++) this->copy_column(k,0);
	}
	
	map::map() {
		srand(time(0));
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				this->map[i][j] = random() % 3 + 1;
	}
	
	int map::map_query(int x,int y) {
		return this->map[x][y];
	}
	
	bool map::is_end() {
		bool flag = 1;
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				flag = flag && !(this->map[i][j] == this->map[i][j-1] || this->map[i][j] == this->map[i-1][j]);
		return flag;
	}
	
	int map::operation(int x, int y) {
		if (this->map[x][y] == 0) return -1;
		if (!(this->map[i][j] == this->map[i][j-1] || this->map[i][j] == this->map[i-1][j] 
			|| this->map[i][j] == this->map[i+1][j] || this->map[i][j] == this->map[i][j+1])) return -1;
		int sum = 0;
		this->dfs(i, j, f[i][j], sum);
		this->normalization();	
		return sum * sum * 5;
	}
	
	int map::reward_score() {
		int sum=1000;
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				if (a[i][j]) sum-=100;
		return sum<0 ? 0 : sum;
	}
}

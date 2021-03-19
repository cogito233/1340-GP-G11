#include <map.h>

namespace map{
	
	
	map::map(int difficulty_coefficient) {
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
		
		for (int i = 1; i <= 20; i++)
			
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

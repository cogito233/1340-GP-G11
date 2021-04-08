#ifndef map_h
#define map_h

#include <time.h>

namespace mp{
	class map{
		private:
			int f[30][30],score;
			void copy_column(int x,int y);
			void normalization();
			void dfs(int x,int y,int colour,int &sum);
		public:
			map();//生成地图(构造函数)
			int now_score();
			void score_set(int val);
			int map_query(int x, int y);//返回某个点的颜色？
			void map_set(int x, int y, int val);
			bool is_end();//返回0代表地图已经不可消除了
			int operation(int x, int y);//以x,y为中心消除，返回该操作的得分
			void display();//显示地图
	};
}
#endif

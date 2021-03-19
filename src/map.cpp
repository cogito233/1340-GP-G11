#include <bits/stdc++.h>
namespace map{
	class map{
		private:
			int map[30][30];
		public:
			map(int difficulty_coefficient);//生产地图(构造函数)
			int map_query(int x,int y);//返回某个点的颜色？
			bool is_end();//返回0代表地图已经不可消除了
			int operation(int x,int y);//以x,y为中心消除，返回该操作的得分
			int reward_score();//返回当前游戏的奖励分
}
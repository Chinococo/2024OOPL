#pragma once
#include <vector>
#include <queue>
namespace Raiden {
	template<typename T>
	class GameObjectPool
	{
		private:
			std::vector<T *> pool;
			std::queue<T *> recovery;
		public:
			T* operator[](size_t);
			~GameObjectPool();
			void AddElement(std::pair<int, int>);
			void Update();
			void Show();
		};
}

#pragma once
#include <vector>
#include <queue>
namespace Raiden {

	/*
	 * The T should atleast have three methods:
	 * 1. void Init(int left, int top);
	 * 2. bool IsAlive() const;
	 * 3. void Show();
	 */

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

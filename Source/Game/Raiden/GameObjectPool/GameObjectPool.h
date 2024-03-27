#pragma once
#include <vector>
#include <queue>
#include <memory>

namespace Raiden
{
	/**
	 * The T should atleast have three methods:
	 * 1. void Init(int left, int top);
	 * 2. bool IsAlive() const;
	 * 3. void Show();
	 */
	template<typename T>
	class GameObjectPool
	{
	public:
		void AddElement();
		void Update();
		void Show();
		std::shared_ptr<T> operator[](std::size_t index);

	private:
		std::vector<std::shared_ptr<T>> pool;
		std::queue<std::shared_ptr<T>> recovery;
	};
}

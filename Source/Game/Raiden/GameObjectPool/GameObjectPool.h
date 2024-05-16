#pragma once
#include <vector>
#include <queue>
#include <memory>

namespace Raiden
{
	/**
	 * The T should atleast have three methods:
	 * 1. void Init();
	 * 2. bool IsAlive() const;
	 * 3. void Show();
	 */
	template<typename T>
	class GameObjectPool
	{
	public:
		int AddElement();
		void Update();
		void Show();
		std::size_t GetSize() const;
		std::shared_ptr<T> operator[](std::size_t index);
		void Clear();
		std::vector<std::shared_ptr<T>> GetPoolVec();

	private:
		std::vector<std::shared_ptr<T>> pool;
		std::queue<std::shared_ptr<T>> recovery;

	};
}

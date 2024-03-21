#include "stdafx.h"
#include "GameObjectPool.h"
#include "../Fighter/Fighter.h"
#include <vector>

namespace Raiden
{
	template<typename T>
	GameObjectPool<T>::~GameObjectPool()
	{
		for (size_t i = 0; i < pool.size(); i++)
			delete pool[i];

		while (recovery.size()) {
			delete recovery.front();
			recovery.pop();
		}
	}

	template<typename T>
	void GameObjectPool<T>::AddElement(std::pair<int,int> position)
	{
		if (this->recovery.size() > 0)
		{
			T * temp = recovery.front();
			temp->Init(position.first, position.second);
			pool.push_back(temp);
			recovery.pop();
		}
		else
		{
			T * temp = new T();
			temp->Init(position.first, position.second);
			pool.push_back(temp);
		}
	}

	template<typename T>
	void GameObjectPool<T>::Update()
	{
		for (size_t i = 0; i < pool.size(); )
		{
			if (!(bool)pool[i]->IsAlive())
			{
				recovery.push(pool[i]);
				pool.erase(pool.begin() + i);
				continue;
			}
			i++;
		}
	}

	template<typename T>
	T* GameObjectPool<T>::operator[](size_t index)
	{
		return pool[index];
	}

	template<typename T>
	void GameObjectPool<T>::Show()
	{
		for (size_t i = 0; i < pool.size(); i++)
			pool[i]->Show();
	}

	template class GameObjectPool<Fighter>;
}

#include "stdafx.h"
#include "GameObjectPool.h"
#include "../Fighter/Fighter.h"
#include "../Bullet/Bullet.h"

namespace Raiden
{
	template<typename T>
	int GameObjectPool<T>::AddElement()
	{
		std::shared_ptr<T> temp;

		if (recovery.size() > 0)
		{
			temp = recovery.front();
			recovery.pop();
		}
		else
		{
			temp = std::make_shared<T>();
		}

		pool.push_back(temp);
		return pool.size() - 1;
	}
	//¤l¼u±M¥Î
	/*
	template<>
	int GameObjectPool<Bullet>::AddElement(CPoint point,CPoint force)
	{
		std::shared_ptr<Bullet> temp;

		if (recovery.size() > 0)
		{
			temp = recovery.front();
			recovery.pop();
		}
		else
		{
			temp = std::make_shared<Bullet>();
		}
		temp->ApplyForce(std::move(force));
		temp->SetTopLeft(std::move(point));
		pool.push_back(temp);
		return pool.size() - 1;
	}*/
	template<typename T>
	void GameObjectPool<T>::Update()
	{
		for (std::size_t i = 0; i < pool.size(); )
		{
			if (!static_cast<bool>(pool[i]->IsAlive()))
			{
				recovery.push(pool[i]);
				pool.erase(pool.begin() + i);
				continue;
			}
			i++;
		}
	}

	template<typename T>
	void GameObjectPool<T>::Show()
	{
		for (std::size_t i = 0; i < pool.size(); i++)
			pool[i]->Show();
	}

	template<typename T>
	std::size_t GameObjectPool<T>::GetSize() const
	{
		return pool.size();
	}

	template<typename T>
	std::shared_ptr<T> GameObjectPool<T>::operator[](std::size_t index)
	{
		return pool[index];
	}

	template class GameObjectPool<Fighter>;
	template class GameObjectPool<Bullet>;
}

#pragma once
#include <string>
#include <map>
#include <vector>
#include <atltypes.h>

namespace Raiden
{
	/**
	 * ���� Register ���U�@�Ӧ�m�è��o�M�� id�C
	 * ����N�ݭn�̾a�o�ӱM�� id �ӿ�{�B�ק�r��C
	 */
	class TextGraphics
	{
	public:
		std::size_t Register(CPoint &&point, std::string text);
		void UpdateText(std::size_t id, std::string text);
		void Show() const;
		void Clear();

	private:
		std::vector<CPoint> points;
		std::vector<std::string> texts;
	};
}

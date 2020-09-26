#ifndef COLOR_H
#define COLOR_H

namespace engine
{
	struct Color
	{
	public:
		inline Color()
		{
			m_R = 0;
			m_G = 0;
			m_B = 0;
		}

		inline Color(int r, int g, int b)
		{
			m_R = r;
			m_G = g;
			m_B = b;
		}

		inline int GetR() { return m_R; }
		inline int GetG() { return m_G; }
		inline int GetB() { return m_B; }

		inline void SetR(int r) { m_R = r; }
		inline void SetG(int g) { m_G = g; }
		inline void SetB(int b) { m_B = b; }

	private:
		int m_R, m_G, m_B;
	};
}

#endif // !COLOR_H
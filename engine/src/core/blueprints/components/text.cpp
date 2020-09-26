#include "core/blueprints/components/transform.h"
#include "text.h"

namespace engine
{
	Text::~Text()
	{
		TTF_CloseFont(m_Font);
		SDL_FreeSurface(m_Surface);
		SDL_DestroyTexture(m_Texture);
	}

	void Text::Birth()
	{
		m_Font = TTF_OpenFont(m_Path.c_str(), m_FontSize);
		m_OwnerTransform = GetOwner()->GetComponent<Transform>();
		UpdateText(m_Text);
	}

	void Text::UpdateText(const std::string& text)
	{
		SDL_Color color;
		color.r = m_Color.GetR();
		color.g = m_Color.GetG();
		color.b = m_Color.GetB();

		m_Text = text;
		m_Surface = TTF_RenderText_Solid(m_Font, m_Text.c_str(), color);
		m_Texture = SDL_CreateTextureFromSurface(m_Renderer, m_Surface);
	}

	void Text::Render()
	{
		SDL_Rect referenceRect = { m_OwnerTransform->GetPosition().GetX() - m_OwnerTransform->GetScale().GetX() / 2, m_OwnerTransform->GetPosition().GetY(), 
			m_OwnerTransform->GetScale().GetX(), m_OwnerTransform->GetScale().GetY() };

		SDL_RenderCopy(m_Renderer, m_Texture, nullptr, &referenceRect);
	}
}
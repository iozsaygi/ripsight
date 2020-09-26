#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "public/engine_entry.h"
#include "public/color.h"
#include "core/common/actor.h"
#include "core/common/component.h"

namespace engine
{
	class Transform;

	class Text : public engine::Component
	{
	public:
		inline Text(engine::Actor* owner, engine::EngineEntry* engineEntry, const std::string& path, const std::string& initialText,
			int fontSize, engine::Color color) : Component(owner)
		{
			m_Renderer = engineEntry->GetRenderer();

			m_Path = path;
			m_FontSize = fontSize;
			m_Text = initialText;
			
			m_Color.SetR(color.GetR());
			m_Color.SetG(color.GetG());
			m_Color.SetB(color.GetB());
		}

		~Text();

		void Birth() override;
		void UpdateText(const std::string& text);
		void Render();

	private:
		std::string m_Path;
		TTF_Font* m_Font = nullptr;
		int m_FontSize = 0;
		Color m_Color;
		SDL_Renderer* m_Renderer = nullptr;
		SDL_Surface* m_Surface = nullptr;
		SDL_Texture* m_Texture = nullptr;
		std::string m_Text;
		Transform* m_OwnerTransform = nullptr;
	};
}

#endif // !TEXT_H
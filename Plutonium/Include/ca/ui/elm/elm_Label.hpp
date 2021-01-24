#pragma once

#include <ca/ui/elm/elm_Image.hpp>

namespace ca::ui::elm
{
    class Label : public Image
    {
        public:
            Label(i32 x, i32 y, pu::String text, pu::ui::Color color);
            PU_SMART_CTOR(Label);

            void SetColor(pu::ui::Color color);
            void SetFont(pu::String font);
            void SetText(pu::String text);
        
        private:
            void UpdateTexture();

        private:
            pu::ui::Color color;
            pu::String font;
            pu::String text;
    };
}
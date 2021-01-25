#pragma once

#include <ca/ui/elm/elm_SelectableElement.hpp>
#include <ca/ui/elm/elm_Label.hpp>

namespace ca::ui::elm
{
    class Button : public SelectableElement
    {
        public:
            Button(i32 x, i32 y, pu::String text);
            Button(i32 x, i32 y, i32 width, i32 height, pu::String text);
            PU_SMART_CTOR(Button);

            void OnInput(ca::app::Input input) override;
            void OnRender(pu::ui::render::Renderer::Ref renderer) override;

        private:
            Label::Ref label;
    };
}
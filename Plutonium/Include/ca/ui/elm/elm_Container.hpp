#pragma once

#include <vector>
#include <ca/ui/elm/elm_Element.hpp>
#include <ca/app/app_Input.hpp>

namespace ca::ui::elm
{
    class Container : public Element
    {
        public:
            Container(i32 x, i32 y, i32 width, i32 height);
            PU_SMART_CTOR(Container);

            void AddChild(Element::Ref element);
            void RemoveChild(Element::Ref element);
            bool Contains(Element::Ref element);

            void SetBackgroundColor(pu::ui::Color value);
            void ClearBackgroundColor();

            void OnInput(ca::app::Input input) override;
            void OnRender(pu::ui::render::Renderer::Ref renderer) override;

        protected:
            virtual void OnRenderBeforeChildren(pu::ui::render::Renderer::Ref renderer) {}
            virtual void OnRenderAfterChildren(pu::ui::render::Renderer::Ref renderer) {}

        private:
            int IndexOf(Element::Ref element);

        private:
            std::vector<Element::Ref> children;
            pu::ui::Color backgroundColor;
    };

}
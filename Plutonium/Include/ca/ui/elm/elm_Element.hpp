#pragma once

#include <memory>
#include <ca/app/app_Input.hpp>
#include <ca/ui/ui_Alignments.hpp>
#include <pu/pu_Macros.hpp>
#include <pu/ui/render/render_Renderer.hpp>

namespace ca::ui::elm
{
    class Element
    {
        public:
            Element(i32 x, i32 y, i32 width, i32 height);
            PU_SMART_CTOR(Element);

            i32 GetX() { return this->x; }
            i32 GetY() { return this->y; }
            i32 GetWidth() { return this->width; }
            i32 GetHeight() { return this->height; }

            i32 GetProcessedX();
            i32 GetProcessedY();

            Element::Ref GetParent() { return this->parent; }
            void SetParent(Element::Ref element) { this->parent = element; }

            void SetHorizontalAlignment(HorizontalAlignment horizontalAligment) { this->horizontalAlignment = horizontalAlignment; }
            HorizontalAlignment GetHorizontalAlignment() { return this->horizontalAlignment; }

            void SetVerticalAlignment(VerticalAlignment verticalAlignment) { this->verticalAlignment = verticalAlignment; }
            VerticalAlignment GetVerticalAlignment() { return this->verticalAlignment; }

            virtual void OnInput(app::Input input) {}
            virtual void OnRender(pu::ui::render::Renderer::Ref renderer) = 0;

        protected:
            i32 x;
            i32 y;
            i32 width;
            i32 height;

            Element::Ref parent;

            HorizontalAlignment horizontalAlignment;
            VerticalAlignment verticalAlignment;
    };
}
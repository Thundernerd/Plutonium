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

            i32 GetX();
            i32 GetY();
            i32 GetWidth();
            i32 GetHeight();

            i32 GetProcessedX();
            i32 GetProcessedY();

            void SetX(i32 value);
            void SetY(i32 value);
            void SetWidth(i32 value);
            void SetHeight(i32 value);
            void SetPosition(i32 x, i32 y);
            void SetSize(i32 width, i32 height);

            Element* GetParent();
            void SetParent(Element* element);

            void SetHorizontalAlignment(HorizontalAlignment horizontalAligment);
            HorizontalAlignment GetHorizontalAlignment();

            void SetVerticalAlignment(VerticalAlignment verticalAlignment);
            VerticalAlignment GetVerticalAlignment();

            virtual void OnInput(app::Input input) {}
            virtual void OnRender(pu::ui::render::Renderer::Ref renderer) = 0;

        private:
            i32 x;
            i32 y;
            i32 width;
            i32 height;

            Element* parent;

            HorizontalAlignment horizontalAlignment;
            VerticalAlignment verticalAlignment;
    };
}
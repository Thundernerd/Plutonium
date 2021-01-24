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

            virtual i32 GetX();
            virtual i32 GetY();
            virtual i32 GetWidth();
            virtual i32 GetHeight();

            virtual i32 GetProcessedX();
            virtual i32 GetProcessedY();

            virtual void SetX(i32 value);
            virtual void SetY(i32 value);
            virtual void SetWidth(i32 value);
            virtual void SetHeight(i32 value);
            virtual void SetPosition(i32 x, i32 y);
            virtual void SetSize(i32 width, i32 height);

            virtual Element* GetParent();
            virtual void SetParent(Element* element);

            virtual void SetHorizontalAlignment(HorizontalAlignment horizontalAligment);
            virtual HorizontalAlignment GetHorizontalAlignment();

            virtual void SetVerticalAlignment(VerticalAlignment verticalAlignment);
            virtual VerticalAlignment GetVerticalAlignment();

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
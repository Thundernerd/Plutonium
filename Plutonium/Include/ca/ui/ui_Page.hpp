#pragma once

#include <ca/app/app_Application.hpp>
#include <ca/ui/elm/elm_Container.hpp>
#include <ca/ui/elm/elm_Label.hpp>
#include <pu/ui/render/render_Renderer.hpp>
#include <pu/sdl2/sdl2_Types.hpp>

namespace ca::ui
{
    class Page : public elm::Container
    {
        public:
            Page(pu::String title);
            Page(pu::String title, pu::ui::Color titleColor);
            Page(pu::ui::Color backgroundColor);
            Page(pu::String title, pu::ui::Color titleColor, pu::ui::Color backgroundColor);
            PU_SMART_CTOR(Page);

            i32 GetX() override;
            i32 GetY() override;
            i32 GetWidth() override;
            i32 GetHeight() override;

            void SetTitle(pu::String value);
            void SetTitleColor(pu::ui::Color value);

            virtual void OnShow();
            virtual void OnHide();

            void AddOverlay();
            void PopOverlay();

            void OnInput(ca::app::Input input) override;

        protected:
            void OnRenderBeforeChildren(pu::ui::render::Renderer::Ref renderer) override;
            void OnRenderAfterChildren(pu::ui::render::Renderer::Ref renderer) override;

        private:
            ca::ui::elm::Label::Ref titleLabel;
    };
}
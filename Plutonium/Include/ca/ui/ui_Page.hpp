#pragma once

#include <ca/app/app_Application.hpp>
#include <ca/ui/elm/elm_Element.hpp>
#include <pu/ui/render/render_Renderer.hpp>

namespace ca::ui
{
    class Page : public elm::Element
    {
        public:
            Page();
            PU_SMART_CTOR(Page);

            virtual void Prepare(ca::app::Application::Ref application);

            virtual void OnShow();
            virtual void OnHide();

            void AddElement(Element::Ref element);
            void RemoveElement(Element::Ref element);

            void AddOverlay();
            void PopOverlay();

            void OnInput(ca::app::Input input) override;
            void OnRender(pu::ui::render::Renderer::Ref renderer) override;

        protected:
            ca::app::Application::Ref application;
            std::vector<Element::Ref> elements;
    };
}
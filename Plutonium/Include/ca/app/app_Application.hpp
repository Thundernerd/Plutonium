#pragma once

#include <pu/pu_Macros.hpp>
#include <pu/ui/render/render_Renderer.hpp>

namespace ca::app
{
    class Application
    {
        public:
            Application(pu::ui::render::Renderer::Ref renderer);
            PU_SMART_CTOR(Application);

            void Prepare();
            void Show();
            void Hide();

            bool IsLoaded() { return this->isLoaded; }
            bool IsShown() { return this->isShown; }

        protected:
            virtual void OnLoad() = 0;
            virtual void OnRender(pu::ui::render::Renderer::Ref renderer) = 0;

        protected:
            pu::ui::Color clearColor;

        private:
            bool CallForRender();

        private:
            bool isLoaded;
            bool isShown;
            pu::ui::render::Renderer::Ref renderer;
    };
}
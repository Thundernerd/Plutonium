#pragma once

#include <vector>
#include <ca/app/app_Application.hpp>
#include <ca/ui/ui_Page.hpp>

namespace ca::app
{
    class PagedApplication : public Application, public std::enable_shared_from_this<PagedApplication>
    {
        public:
            PagedApplication(pu::ui::render::Renderer::Ref renderer);
            PU_SMART_CTOR(PagedApplication);

            void ShowPage(ui::Page::Ref page);
            void HidePage(ui::Page::Ref page);
            void Back();

        protected:
            void OnRender(pu::ui::render::Renderer::Ref renderer);

        private:
            void LoadPage(ui::Page::Ref page);
            int IndexOf(ui::Page::Ref page);

        private:
            ui::Page::Ref currentPage;
            std::vector<ui::Page::Ref> pages;
    };
}
#include <ca/app/app_PagedApplication.hpp>

namespace ca::app
{
    PagedApplication::PagedApplication(pu::ui::render::Renderer::Ref renderer) : Application(renderer)
    {

    }

    void PagedApplication::ShowPage(ui::Page::Ref page)
    {
        this->pages.push_back(page);
        this->LoadPage(page);
    }

    void PagedApplication::HidePage(ui::Page::Ref page)
    {
        int index = this->IndexOf(page);
        if (index == -1)
        {
            return;
        }

        this->pages.erase(this->pages.begin() + index);
        page->OnHide();
    }

    void PagedApplication::Back()
    {
        if (this->pages.size() == 0)
        {
            return;
        }

        ui::Page::Ref last = this->pages.at(this->pages.size()-1);
        last->OnHide();
        this->pages.pop_back();

        last = this->pages.at(this->pages.size()-1);
        this->LoadPage(last);
    }

    void PagedApplication::OnRender(pu::ui::render::Renderer::Ref renderer)
    {
        if (this->currentPage == nullptr)
        {
            return;
        }

        this->input.Update();
        this->currentPage->OnInput(this->input);
        this->currentPage->OnRender(renderer);
    }

    void PagedApplication::LoadPage(ui::Page::Ref page)
    {
        this->currentPage = page;
        page->Prepare(shared_from_this());
        page->OnShow();
    }

    int PagedApplication::IndexOf(ui::Page::Ref page)
    {
        for(auto i = 0; i < this->pages.size(); i++)
        {
            auto item = this->pages.at(i);
            if (item == page)
                return i;
        }

        return -1;
    }
}
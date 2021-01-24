#include <ca/ui/ui_Page.hpp>
#include <ca/ui/ui_Colors.hpp>

namespace ca::ui
{
    Page::Page(pu::String title) : Page(title, Colors::Light, Colors::Dark)
    {
    }

    Page::Page(pu::String title, pu::ui::Color titleColor) : Page(title, titleColor, Colors::Dark)
    {
    }

    Page::Page(pu::ui::Color backgroundColor) : Page("", HexColor("#00000000"), backgroundColor)
    {
    }

    Page::Page(pu::String title, pu::ui::Color titleColor, pu::ui::Color backgroundColor) : elm::Container(0,0,1280,720)
    {
        this->title = title;
        this->titleColor = titleColor;
        this->SetBackgroundColor(backgroundColor);
    }

    i32 Page::GetX()
    {
        return 0;
    }

    i32 Page::GetY()
    {
        return 100;
    }

    i32 Page::GetWidth()
    {
        return 1280;
    }

    i32 Page::GetHeight()
    {
        return 620;
    }

    void Page::SetTitle(pu::String value)
    {
        this->title = value;
    }

    void Page::SetTitleColor(pu::ui::Color value)
    {
        this->titleColor = value;
    }

    void Page::OnShow()
    {
    }

    void Page::OnHide()
    {
    }

    void Page::AddOverlay()
    {
    }

    void Page::PopOverlay()
    {
    }

    void Page::OnInput(ca::app::Input input)
    {
        Container::OnInput(input);
    }

    void Page::OnRenderBeforeChildren(pu::ui::render::Renderer::Ref renderer)
    {
        if (this->title == "")
        {
            renderer->RenderRectangleFill(this->GetBackgroundColor(), 0, 0, 1280, 100);
            return;
        }

        renderer->RenderRectangleFill(Colors::Dark, 0, 0, 1280, 100);
        // renderer->RenderTexture(this->titleTexture, 0, 0);
    }

    void Page::OnRenderAfterChildren(pu::ui::render::Renderer::Ref renderer)
    {
        if (this->title == "")
        {
            return;
        }

        renderer->RenderRectangle(Colors::Light, 20, 99, 1240, 2);
    }

    void Page::UpdateTitleTexture()
    {
        
    }
}
#include <ca/ui/ui_Page.hpp>
#include <ca/ui/ui_Colors.hpp>

namespace ca::ui
{
    Page::Page(pu::String title) : Page(title, Colors::Foreground, Colors::Background)
    {
    }

    Page::Page(pu::String title, pu::ui::Color titleColor) : Page(title, titleColor, Colors::Background)
    {
    }

    Page::Page(pu::ui::Color backgroundColor) : Page("", HexColor("#00000000"), backgroundColor)
    {
    }

    Page::Page(pu::String title, pu::ui::Color titleColor, pu::ui::Color backgroundColor) : elm::Container(0,0,1280,720)
    {
        this->titleLabel = ca::ui::elm::Label::New(70, 0, title, "DefaultFont@30", titleColor);
        
        auto height = this->titleLabel->GetHeight();
        this->titleLabel->SetY(55-(height/2));

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
        this->titleLabel->SetText(value);
    }

    void Page::SetTitleColor(pu::ui::Color value)
    {
        this->titleLabel->SetColor(value);
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
        if (this->titleLabel->GetText() == "")
        {
            renderer->RenderRectangleFill(this->GetBackgroundColor(), 0, 0, 1280, 100);
            return;
        }

        renderer->RenderRectangleFill(Colors::Background, 0, 0, 1280, 100);
        this->titleLabel->OnRender(renderer);
    }

    void Page::OnRenderAfterChildren(pu::ui::render::Renderer::Ref renderer)
    {
        if (this->titleLabel->GetText() == "")
        {
            return;
        }

        renderer->RenderRectangle(Colors::Foreground, 40, 100, 1200, 1);
    }
}
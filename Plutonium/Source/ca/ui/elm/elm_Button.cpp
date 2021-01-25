#include <ca/ui/elm/elm_Button.hpp>
#include <ca/ui/ui_Colors.hpp>

namespace ca::ui::elm
{
    Button::Button(i32 x, i32 y, pu::String text) : SelectableElement(x, y, 0, 0)
    {
        this->label = Label::New(2,2, text, Colors::Foreground);
        this->label->SetHorizontalAlignment(HorizontalAlignment::Center);
        this->label->SetVerticalAlignment(VerticalAlignment::Center);
        this->SetWidth(this->label->GetWidth()+120);
        this->SetHeight(this->label->GetHeight()+60);
        this->label->SetParent(this);
    }

    Button::Button(i32 x, i32 y, i32 width, i32 height, pu::String text) : SelectableElement(x, y, width, height)
    {
        this->label = Label::New(x, y, text, Colors::Foreground);
    }

    void Button::OnInput(ca::app::Input input)
    {
        if (!this->IsSelected())
        {
            return;
        }

        if (input.IsDown(KEY_A))
        {
            // Invoke something
        }
    }

    void Button::OnRender(pu::ui::render::Renderer::Ref renderer)
    {
        const int x = this->GetProcessedX();
        const int y = this->GetProcessedY();
        const int w = this->GetWidth();
        const int h = this->GetHeight();
        const int size = 4;
        const int radius = 3;

        renderer->RenderRectangleBorder(Colors::Foreground, x, y, w, h, size);
        this->label->OnRender(renderer);

        if (this->IsSelected())
        {
            renderer->RenderRectangleBorder(Colors::Primary, x, y, w, h, size); 
        }
    }
}
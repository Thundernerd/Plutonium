#include <ca/ui/elm/elm_Label.hpp>

namespace ca::ui::elm
{
    Label::Label(i32 x, i32 y, pu::String text, pu::ui::Color color) : Label(x,y,text,"DefaultFont@25", color)
    {
    }

    Label::Label(i32 x, i32 y, pu::String text, pu::String font, pu::ui::Color color) : Image(x, y, "")
    {
        this->color = color;
        this->font = font;
        this->text = text;

        this->UpdateTexture();
    }

    void Label::SetColor(pu::ui::Color color)
    {
        this->color = color;
        this->UpdateTexture();
    }

    void Label::SetFont(pu::String font)
    {
        this->font = font;
        this->UpdateTexture();
    }

    void Label::SetText(pu::String text)
    {
        this->text = text;
        this->UpdateTexture();
    }

    pu::ui::Color Label::GetColor()
    {
        return this->color;
    }

    pu::String Label::GetFont()
    {
        return this->font;
    }

    pu::String Label::GetText()
    {
        return this->text;
    }

    void Label::UpdateTexture()
    {
        this->SetTexture(pu::ui::render::RenderText(this->font, this->text, this->color));
        this->SetWidth(pu::ui::render::GetTextWidth(this->font,this->text));
        this->SetHeight(pu::ui::render::GetTextHeight(this->font,this->text));
    }
}
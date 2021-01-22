#include <ca/ui/elm/elm_Element.hpp>

namespace ca::ui::elm
{
    Element::Element(i32 x, i32 y, i32 width, i32 height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    i32 Element::GetProcessedX()
    {
        i32 x = 0;
        if (this->parent != nullptr)
        {
            x = this->parent->GetProcessedX();
        }

        switch(this->horizontalAlignment)
        {
            case HorizontalAlignment::Center:
                x += ((this->parent->GetWidth() / 2) - (this->GetWidth() / 2) + this->GetX());
                break;
            case HorizontalAlignment::Left:
                x += this->GetX();
                break;
            case HorizontalAlignment::Right:
                x += (this->parent->GetWidth() - this->GetWidth() - this->GetX());
                break;
        }

        return x;
    }

    i32 Element::GetProcessedY()
    {
        i32 y = 0;
        if (this->parent != nullptr)
        {
            y = this->parent->GetProcessedY();
        }

        switch (this->verticalAlignment)
        {
            case VerticalAlignment::Bottom:
                y += this->GetY();
                break;
            case VerticalAlignment::Center:
                y += ((this->parent->GetHeight() / 2) - (this->GetHeight() / 2) + this->GetY());
                break;
            case VerticalAlignment::Top:
                y += (this->parent->GetHeight() - this->GetHeight() - this->GetY());
                break;
        }

        return y;
    }
}
#include <ca/ui/elm/elm_Element.hpp>

namespace ca::ui::elm
{
    Element::Element(i32 x, i32 y, i32 width, i32 height)
    {
        this->parent = nullptr;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->horizontalAlignment = HorizontalAlignment::Right;
        this->verticalAlignment = VerticalAlignment::Top;
    }

    i32 Element::GetX()
    {
        return this->x;
    }

    i32 Element::GetY()
    {
        return this->y;
    }

    i32 Element::GetWidth()
    {
        return this->width;
    }

    i32 Element::GetHeight()
    {
        return this->height;
    }

    i32 Element::GetProcessedX()
    {
        i32 x = 0;
        i32 pw = 0;
        
        if (this->parent != nullptr)
        {
            x = this->parent->GetProcessedX();
            pw = this->parent->GetWidth();
        } 
        else
        {
            pw = 1280;
        }

        switch(this->horizontalAlignment)
        {
            case HorizontalAlignment::Left:
                x += this->GetX();
                break;
            case HorizontalAlignment::Center:
                x += ((pw / 2) - (this->GetWidth() / 2) + this->GetX());
                break;
            case HorizontalAlignment::Right:
                x += (pw - this->GetWidth() - this->GetX());
                break;
        }

        return x;
    }

    i32 Element::GetProcessedY()
    {
        i32 y = 0;
        i32 ph = 0;
        if (this->parent != nullptr)
        {
            y = this->parent->GetProcessedY();
            ph = this->parent->GetHeight();
        }
        else
        {
            ph = 720;
        }

        switch (this->verticalAlignment)
        {
            case VerticalAlignment::Top:
                y += this->GetY();
                break;
            case VerticalAlignment::Center:
                y += ((ph / 2) - (this->GetHeight() / 2) + this->GetY());
                break;
            case VerticalAlignment::Bottom:
                y += (ph - this->GetHeight() - this->GetY());
                break;
        }

        return y;
    }

    void Element::SetX(i32 value)
    {
        this->x = value;
    }

    void Element::SetY(i32 value)
    {
        this->y = value;
    }

    void Element::SetWidth(i32 value)
    {
        this->width = value;
    }

    void Element::SetHeight(i32 value)
    {
        this->height = value;
    }

    void Element::SetPosition(i32 x, i32 y)
    {
        this->SetX(x);
        this->SetY(y);
    }

    void Element::SetSize(i32 width, i32 height)
    {
        this->SetWidth(width);
        this->SetHeight(height);
    }

    Element* Element::GetParent()
    {
        return this->parent;
    }

    void Element::SetParent(Element* element)
    {
        this->parent = element;
    }

    void Element::SetHorizontalAlignment(HorizontalAlignment value)
    {
        this->horizontalAlignment = value;
    }

    HorizontalAlignment Element::GetHorizontalAlignment()
    {
        return this->horizontalAlignment;
    }

    void Element::SetVerticalAlignment(VerticalAlignment value)
    {
        this->verticalAlignment = value;
    }

    VerticalAlignment Element::GetVerticalAlignment()
    {
        return this->verticalAlignment;
    }
}
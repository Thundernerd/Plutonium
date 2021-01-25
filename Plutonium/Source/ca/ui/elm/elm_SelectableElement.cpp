#include <ca/ui/elm/elm_SelectableElement.hpp>

namespace ca::ui::elm
{
    SelectableElement::SelectableElement(i32 x, i32 y, i32 width, i32 height) : Element(x, y, width, height)
    {
        this->isSelected = false;
    }

    void SelectableElement::Select()
    {
        if (this->isSelected)
        {
            return;
        }

        this->isSelected = true;
        this->OnSelect();
    }

    void SelectableElement::Deselect()
    {
        if (!this->isSelected)
        {
            return;
        }

        this->isSelected = false;
        this->OnDeselect();
    }

    bool SelectableElement::IsSelected()
    {
        return this->isSelected;
    }

    void SelectableElement::OnSelect()
    {
    }

    void SelectableElement::OnDeselect()
    {
    }
}
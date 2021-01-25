#pragma once

#include <ca/ui/elm/elm_Element.hpp>

namespace ca::ui::elm
{
    class SelectableElement : public Element
    {
        public:
            SelectableElement(i32 x, i32 y, i32 width, i32 height);
            PU_SMART_CTOR(SelectableElement);

            void Select();
            void Deselect();

            bool IsSelected();

        protected:
            virtual void OnSelect();
            virtual void OnDeselect();

        private:
            bool isSelected;
    };
}
#include <ca/ui/ui_Page.hpp>

namespace ca::ui
{
    Page::Page() : Element(0,0,1280,720)
    {
    }

    void Page::Prepare(ca::app::Application::Ref application)
    {
        this->application = application;
    }

    void Page::OnShow()
    {
    }

    void Page::OnHide()
    {
    }

    void Page::AddElement(Element::Ref element)
    {
        if (element == nullptr)
        {
            return;
        }

        Element::Ref parent = element->GetParent();
        if (element != nullptr && std::is_same<Page, decltype(parent)>::value)
        {
            std::shared_ptr<Page> parentPage = std::dynamic_pointer_cast<Page>(parent);
            parentPage->RemoveElement(element);
        }

        element->SetParent(shared_from_this());
        this->elements.push_back(element);
    }

    void Page::RemoveElement(Element::Ref element)
    {
        i32 index = 0;
        for(i32 i = 0; i < this->elements.size(); i++)
        {
            Element::Ref item = this->elements.at(i);
            if (item == element)
            {
                index = i;
                break;
            }
        }

        this->elements.erase(this->elements.begin() + index);
        element->SetParent(nullptr);
    }

    void Page::AddOverlay()
    {

    }

    void Page::PopOverlay()
    {

    }

    void Page::OnInput(ca::app::Input input)
    {
        std::vector<Element::Ref> currentElements(this->elements);

        for(Element::Ref element : elements)
        {
            element->OnInput(input);
        }
    }

    void Page::OnRender(pu::ui::render::Renderer::Ref renderer)
    {
        std::vector<Element::Ref> currentElements(this->elements);

        for(Element::Ref element : elements)
        {
            element->OnRender(renderer);
        }
    }
}
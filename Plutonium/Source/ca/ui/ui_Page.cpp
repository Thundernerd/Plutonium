#include <ca/ui/ui_Page.hpp>

namespace ca::ui
{
    Page::Page() : elm::Element(0,0,1280,720), std::enable_shared_from_this<Page>()
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

        Element* parent = element->GetParent();
        if (parent != nullptr && std::is_same<Page, decltype(parent)>::value)
        {
            Page* parentPage = (Page*)parent;
            parentPage->RemoveElement(element);
        }

        element->SetParent(this);
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
        std::vector<std::shared_ptr<Element>> currentElements(this->elements);

        for (int i = 0; i < currentElements.size(); i++)
        {
            auto item = currentElements.at(i);
            item->OnRender(renderer);
        }
    }
}
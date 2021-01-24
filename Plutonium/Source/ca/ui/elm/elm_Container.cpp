#include <ca/ui/elm/elm_Container.hpp>

namespace ca::ui::elm
{
    Container::Container(i32 x, i32 y, i32 width, i32 height) : Element(x,y,width,height)
    {
    }

    void Container::AddChild(Element::Ref element)
    {
        if (element == nullptr)
        {
            return;
        }

        Element* parent = element->GetParent();
        if (parent != nullptr && std::is_base_of<Container, decltype(parent)>::value)
        {
            Container* parentContainer = (Container*)parent;
            parentContainer->RemoveChild(element);
        }

        element->SetParent(this);
        this->children.push_back(element);
    }

    void Container::RemoveChild(Element::Ref element)
    {
        int index = this->IndexOf(element);
        if (index < 0)
        {
            return;
        }

        this->children.erase(this->children.begin()+index);
        element->SetParent(nullptr);
    }

    bool Container::Contains(Element::Ref element)
    {
        return this->IndexOf(element) != -1;
    }

    void Container::SetBackgroundColor(pu::ui::Color value)
    {
        this->backgroundColor = value;
    }

    void Container::ClearBackgroundColor()
    {
        this->backgroundColor = pu::ui::Color::FromHex("#00000000");
    }

    void Container::OnInput(ca::app::Input input)
    {
        auto copy = std::vector<Element::Ref>(this->children);
        for(int i = 0; i < copy.size(); i++)
        {
            auto item = copy.at(i);
            item->OnInput(input);
        }
    }

    void Container::OnRender(pu::ui::render::Renderer::Ref renderer)
    {
        renderer->RenderRectangleFill(this->backgroundColor, 
                this->GetProcessedX(), this->GetProcessedY(), this->GetWidth(), this->GetHeight());

        this->OnRenderBeforeChildren(renderer);

        auto copy = std::vector<Element::Ref>(this->children);
        for(int i = 0; i < copy.size(); i++)
        {
            auto item = copy.at(i);
            item->OnRender(renderer);
        }

        this->OnRenderAfterChildren(renderer);
    }

    std::vector<Element::Ref> Container::GetChildren()
    {
        return this->children;
    }

    pu::ui::Color Container::GetBackgroundColor()
    {
        return this->backgroundColor;
    }

    int Container::IndexOf(Element::Ref element)
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            if (this->children.at(i) == element)
            {
                return i;
            }
        }

        return -1;
    }
}
#include <ca/app/app_Application.hpp>

namespace ca::app
{
    Application::Application(pu::ui::render::Renderer::Ref renderer)
    {
        this->isLoaded = false;
        this->isShown = false;
        this->clearColor = pu::ui::Color::FromHex("#6495ed");
        this->renderer = renderer;
    }

    void Application::Prepare()
    {
        if (this->isLoaded)
        {
            return;
        }

        this->renderer->Initialize();
        this->OnLoad();
        this->isLoaded = true;
    }

    void Application::Show()
    {
        if (!this->isLoaded)
        {
            return;
        }

        this->isShown = true;

        while(this->isShown)
        {
            this->CallForRender();
        }
    }

    void Application::Hide()
    {
        this->isShown = false;
        this->renderer->Finalize();
    }

    bool Application::CallForRender()
    {
        if (!this->isLoaded)
        {
            return false;
        }

        if (!this->isShown)
        {
            return false;
        }

        this->renderer->InitializeRender(this->clearColor);
        this->OnRender(this->renderer);
        this->renderer->FinalizeRender();
        
        return true;
    }
}
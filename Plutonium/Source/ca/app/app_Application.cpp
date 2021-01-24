#include <ca/app/app_Application.hpp>

namespace ca::app
{
    Application::Application(pu::ui::render::Renderer::Ref renderer)
    {
        this->isLoaded = false;
        this->isShown = false;
        this->clearColor = HexColor("#6495ed");
        this->renderer = renderer;

        ca::ui::Colors::SetStyle(
            // Primary, Secondary
            HexColor("#0D6EFD"), HexColor("#6C757D"), 
            // Success, Danger, Warning, Info
            HexColor("#198754"), HexColor("#DC3545"), HexColor("#FFC107"), HexColor("#0DCAF0"), 
            // Light, Dark
            HexColor("#F8F9FA"), HexColor("#212529"));
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
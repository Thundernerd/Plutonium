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
            HexColor("#00FEC5"), HexColor("#1D9BF3"), 
            // Foreground, Background, BackgroundSecondary
            HexColor("#FFFFFF"), HexColor("#2D2D2D"), HexColor("#323232"), 
            // Overlay, OverlaySecondary
            HexColor("#464646"), HexColor("#4B4B4B"));
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
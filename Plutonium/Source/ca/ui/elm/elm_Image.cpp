#include <ca/ui/elm/elm_Image.hpp>

namespace ca::ui::elm
{
    Image::Image(i32 x, i32 y, pu::String path) : Image(x,y,path,0)
    {

    }

    Image::Image(i32 x, i32 y, pu::String path, i32 angle) : Element(x,y,0,0)
    {
        this->options = pu::ui::render::TextureRenderOptions::Default;
        this->options.Angle = angle;
        this->LoadTextureFromFile(path);
    }

    Image::~Image()
    {
        this->DeleteTexture();
    }

    void Image::DeleteTexture()
    {
        if (this->texture != nullptr)
        {
            pu::ui::render::DeleteTexture(this->texture);
            this->texture = nullptr;
        }
    }

    void Image::LoadTextureFromFile(pu::String path)
    {
        if (path == "")
        {
            return;
        }

        std::ifstream inputStream(path.AsUTF8());
        bool isValidFile = inputStream.good();
        inputStream.close();
        
        if (!isValidFile)
        {
            return;
        }

        this->SetTexture(pu::ui::render::LoadImage(path.AsUTF8()));
    }

    void Image::SetTexture(pu::sdl2::Texture texture)
    {
        // this->DeleteTexture();
        this->texture = texture;
        auto w = pu::ui::render::GetTextureWidth(this->texture);
        auto h = pu::ui::render::GetTextureHeight(this->texture);
        this->options.Width = w;
        this->options.Height = h;
        this->SetWidth(w);
        this->SetHeight(h);
    }

    void Image::OnRender(pu::ui::render::Renderer::Ref renderer)
    {
        renderer->RenderTexture(this->texture, this->GetProcessedX(), this->GetProcessedY());
    }
}
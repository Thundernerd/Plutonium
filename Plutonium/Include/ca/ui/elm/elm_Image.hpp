#pragma once

#include <ca/ui/elm/elm_Element.hpp>
#include <pu/pu_String.hpp>
#include <pu/sdl2/sdl2_Types.hpp>

namespace ca::ui::elm
{
    class Image : public Element
    {
        public:
            Image(i32 x, i32 y, pu::String path);
            Image(i32 x, i32 y, pu::String path, i32 angle);
            ~Image();
            PU_SMART_CTOR(Image);

            i32 GetRotation() { return this->options.Angle; }
            void SetRotation(i32 angle) { this->options.Angle = angle; }

            void OnRender(pu::ui::render::Renderer::Ref renderer) override;

        protected:
            void DeleteTexture();
            void SetTexture(pu::sdl2::Texture texture);

        private:
            void LoadTextureFromFile(pu::String path);

        protected:
            pu::sdl2::Texture texture;
            pu::ui::render::TextureRenderOptions options;
    };
}
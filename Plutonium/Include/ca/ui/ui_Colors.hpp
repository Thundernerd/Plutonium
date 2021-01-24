#pragma once

#include <pu/ui/ui_Types.hpp>

#define HexColor(value) pu::ui::Color::FromHex(value)

namespace ca::ui
{
    class Colors
    {
        public:
            static pu::ui::Color Primary;
            static pu::ui::Color Secondary;
            static pu::ui::Color Success;
            static pu::ui::Color Danger;
            static pu::ui::Color Warning;
            static pu::ui::Color Info;
            static pu::ui::Color Light;
            static pu::ui::Color Dark;

            static void SetStyle(pu::ui::Color primary, pu::ui::Color secondary, pu::ui::Color success, pu::ui::Color danger, pu::ui::Color warning, pu::ui::Color info, pu::ui::Color light, pu::ui::Color dark);
    };
}
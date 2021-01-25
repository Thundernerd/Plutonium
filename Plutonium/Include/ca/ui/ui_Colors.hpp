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
            static pu::ui::Color Background;
            static pu::ui::Color BackgroundSecondary;
            static pu::ui::Color Overlay;
            static pu::ui::Color OverlaySecondary;
            static pu::ui::Color Foreground;

            static void SetStyle(pu::ui::Color primary, pu::ui::Color secondary, pu::ui::Color foreground, pu::ui::Color background, pu::ui::Color BackgroundSecondary, pu::ui::Color overlay, pu::ui::Color overlaySecondary);
    };
}
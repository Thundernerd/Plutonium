#include <ca/ui/ui_Colors.hpp>

namespace ca::ui
{
    pu::ui::Color Colors::Primary;
    pu::ui::Color Colors::Secondary;
    pu::ui::Color Colors::Foreground;
    pu::ui::Color Colors::Background;
    pu::ui::Color Colors::BackgroundSecondary;
    pu::ui::Color Colors::Overlay;
    pu::ui::Color Colors::OverlaySecondary;

    void Colors::SetStyle(pu::ui::Color primary, pu::ui::Color secondary, pu::ui::Color foreground, pu::ui::Color background, pu::ui::Color BackgroundSecondary, pu::ui::Color overlay, pu::ui::Color overlaySecondary)
    {
        Colors::Primary = primary;
        Colors::Secondary = secondary;
        Colors::Foreground = foreground;
        Colors::Background = background;
        Colors::BackgroundSecondary = BackgroundSecondary;
        Colors::Overlay = overlay;
        Colors::OverlaySecondary = overlaySecondary;
    }
}
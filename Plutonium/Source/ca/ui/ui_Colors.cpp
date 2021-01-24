#include <ca/ui/ui_Colors.hpp>

namespace ca::ui
{
    pu::ui::Color Colors::Primary;
    pu::ui::Color Colors::Secondary;
    pu::ui::Color Colors::Success;
    pu::ui::Color Colors::Danger;
    pu::ui::Color Colors::Warning;
    pu::ui::Color Colors::Info;
    pu::ui::Color Colors::Light;
    pu::ui::Color Colors::Dark;

    void Colors::SetStyle(pu::ui::Color primary, pu::ui::Color secondary, pu::ui::Color success, pu::ui::Color danger, pu::ui::Color warning, pu::ui::Color info, pu::ui::Color light, pu::ui::Color dark)
    {
        Colors::Primary = primary;
        Colors::Secondary = secondary;
        Colors::Success = success;
        Colors::Danger = danger;
        Colors::Warning = warning;
        Colors::Info = info;
        Colors::Light = light;
        Colors::Dark = dark;
    }
}
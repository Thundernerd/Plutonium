#pragma once

#include <pu/ui/ui_Types.hpp>

namespace ca::app
{
    class Input
    {
        public:
            void Update();

            bool IsDown(u64 key);
            bool IsUp(u64 key);
            bool IsHeld(u64 key);
            bool HasTouch();
            pu::ui::Touch GetTouch();
        
        private:
            u64 down;
            u64 up;
            u64 held;
            pu::ui::Touch touch;
    };
}
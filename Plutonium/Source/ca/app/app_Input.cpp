#include <ca/app/app_Input.hpp>

namespace ca::app
{
    void Input::Update()
    {
        hidScanInput();
        
        down = hidKeysDown(CONTROLLER_P1_AUTO);
        up = hidKeysUp(CONTROLLER_P1_AUTO);
        held = hidKeysHeld(CONTROLLER_P1_AUTO);
        
        u64 touchHandle = hidKeysDown(CONTROLLER_HANDHELD);
        this->touch = pu::ui::Touch::Empty;

        if (touchHandle & KEY_TOUCH)
        {
            touchPosition tPos;
            hidTouchRead(&tPos, 0);
            this->touch.X = tPos.px;
            this->touch.Y = tPos.py;
        }
    }

    bool Input::IsDown(u64 key)
    {
        return down & key;
    }

    bool Input::IsUp(u64 key)
    {
        return up & key;
    }

    bool Input::IsHeld(u64 key)
    {
        return held & key;
    }

    bool Input::HasTouch()
    {
        return this->touch.IsEmpty();
    }

    pu::ui::Touch Input::GetTouch()
    {
        return this->touch;
    }
}
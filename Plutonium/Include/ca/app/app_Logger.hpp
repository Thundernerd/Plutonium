#pragma once

#include <pu/pu_String.hpp>

namespace ca::app
{
    class Logger
    {
        public:
            void Log(pu::String content);

        private:
            std::string GetCurrentTime();
    };
}
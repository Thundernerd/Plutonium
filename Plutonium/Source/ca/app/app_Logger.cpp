#include <ca/app/app_Logger.hpp>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>

namespace ca::app
{
    void Logger::Log(pu::String content)
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d");
        auto a = ss.str();

        std::fstream fs;
        fs.open("sdmc:/switch/Calcium/log-"+a+".txt", std::fstream::in | std::fstream::out | std::fstream::app);
        fs << GetCurrentTime() << " | " << content.AsUTF8() << "\n";
        fs.close();
    }
    std::string Logger::GetCurrentTime()
    {
        time_t timet = time(NULL);
        struct tm *times = localtime((const time_t*)&timet);
        int h = times->tm_hour;
        int min = times->tm_min;
        int s = times->tm_sec;
        char timestr[0x10] = {0};
        sprintf(timestr, "%02d:%02d:%02d", h, min, s);
        return std::string(timestr);
    }
}
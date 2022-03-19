#include "log_manager.h"

namespace Gaviota
{
    std::shared_ptr<spdlog::logger> LogManager::s_core_logger;

    std::shared_ptr<spdlog::logger> LogManager::s_client_logger;

    LogManager::LogManager()
    {
       
    }

    LogManager::~LogManager()
    {

    }

    void LogManager::Init()
    {
        spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] %v%$");
        s_core_logger = spdlog::stdout_color_mt("GAVIOTA");
        s_core_logger->set_level(spdlog::level::trace);
        
        s_client_logger = spdlog::stdout_color_mt("APP");
        s_client_logger->set_level(spdlog::level::trace);
    }
    
    void LogManager::Stop()
    {

    }
}
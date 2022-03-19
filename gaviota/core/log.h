#ifndef _LOG_
#define _LOG_

#include "spdlog/spdlog.h"

#define GAVIOTA_DEFAULT_LOGGER_NAME "GAVIOTA_LOGGER"

#ifndef GAVIOTA_CONFIG_RELEASE

    #define GAVIOTA_LEVEL_CORE_TRACE(...) ::Gaviota::LogManager::GetCoreLogger()->trace(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CORE_WARN(...)  ::Gaviota::LogManager::GetCoreLogger()->warn(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CORE_ERROR(...) ::Gaviota::LogManager::GetCoreLogger()->error(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CORE_INFO(...)  ::Gaviota::LogManager::GetCoreLogger()->info(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CORE_FATAL(...) ::Gaviota::LogManager::GetCoreLogger()->fatal(__VA_ARGS__)

    #define GAVIOTA_LEVEL_CLIENT_TRACE(...) ::Gaviota::LogManager::GetClientLogger()->trace(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CLIENT_WARN(...)  ::Gaviota::LogManager::GetClientLogger()->warn(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CLIENT_ERROR(...) ::Gaviota::LogManager::GetClientLogger()->error(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CLIENT_INFO(...)  ::Gaviota::LogManager::GetClientLogger()->info(__VA_ARGS__)
    #define GAVIOTA_LEVEL_CLIENT_FATAL(...) ::Gaviota::LogManager::GetClientLogger()->fatal(__VA_ARGS__)

#else
    #define GAVIOTA_LEVEL_CORE_TRACE(...) (void)0
    #define GAVIOTA_LEVEL_CORE_WARN(...)  (void)0
    #define GAVIOTA_LEVEL_CORE_ERROR(...) (void)0
    #define GAVIOTA_LEVEL_CORE_INFO(...)  (void)0
    #define GAVIOTA_LEVEL_CORE_FATAL(...) (void)0

    #define GAVIOTA_LEVEL_CLIENT_TRACE(...) (void)0
    #define GAVIOTA_LEVEL_CLIENT_WARN(...)  (void)0
    #define GAVIOTA_LEVEL_CLIENT_ERROR(...) (void)0
    #define GAVIOTA_LEVEL_CLIENT_INFO(...)  (void)0
    #define GAVIOTA_LEVEL_CLIENT_FATAL(...) (void)0   
#endif

#endif //_LOG_
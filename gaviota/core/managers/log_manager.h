#ifndef _LOG_MANAGER_
#define _LOG_MANAGER_

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "log.h"

/** 
 *  @file   log_manager.h 
 *  @brief  Singleton logger manager
 *  @author Miguel Ravagnani de Carvalho 
 *  @date   2022-11-03 
 **************************************************/
namespace Gaviota
{
    /**
     * @brief Class description
     */
    class LogManager
    {
	public:
		/**
		 * @brief Construct a new Log Manager object
		 */
		LogManager();

		/**
		 * @brief 
		 * 
		 */
		~LogManager();

		/**
		 * @brief Get the Core Logger object
		 * 
		 * @return std::shared_ptr<spdlog::log_clock>& 
		 */
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger;}
		
		/**
		 * @brief Get the Client Logger object
		 * 
		 * @return std::shared_ptr<spdlog::log_clock>& 
		 */
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger;}

		static void Init();
		
		static void Stop();
	
	private:
		/**
		 * @brief Core Logger
		 */
		static std::shared_ptr<spdlog::logger> s_core_logger;
		/**
		 * @brief Client Logger
		 */
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};
}




#endif //_LOG_MANAGER_
 
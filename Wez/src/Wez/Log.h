#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

#include <mutex>

namespace Wez {

	class WEZ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			std::lock_guard<std::mutex> lock(loggerMutex);
			return coreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			std::lock_guard<std::mutex> lock(loggerMutex);
			return clientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
		static std::mutex loggerMutex;
	};

}

// Core log macros
#define WEZ_CORE_TRACE(...)		::Wez::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WEZ_CORE_INFO(...)		::Wez::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WEZ_CORE_WARN(...)		::Wez::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WEZ_CORE_ERROR(...)		::Wez::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WEZ_CORE_FATAL(...)		::Wez::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WEZ_TRACE(...)			::Wez::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WEZ_INFO(...)			::Wez::Log::GetClientLogger()->info(__VA_ARGS__)
#define WEZ_WARN(...)			::Wez::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WEZ_ERROR(...)			::Wez::Log::GetClientLogger()->error(__VA_ARGS__)
#define WEZ_FATAL(...)			::Wez::Log::GetClientLogger()->fatal(__VA_ARGS__)
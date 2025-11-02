#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Wez {

	class WEZ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCorelogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClinetLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

// Core log macros
#define WEZ_CORE_TRACE(...)		::Wez::Log::GetCorelogger()->trace(__VA_ARGS__)
#define WEZ_CORE_INFO(...)		::Wez::Log::GetCorelogger()->info(__VA_ARGS__)
#define WEZ_CORE_WARN(...)		::Wez::Log::GetCorelogger()->warn(__VA_ARGS__)
#define WEZ_CORE_ERROR(...)		::Wez::Log::GetCorelogger()->error(__VA_ARGS__)
#define WEZ_CORE_FATAL(...)		::Wez::Log::GetCorelogger()->fatal(__VA_ARGS__)


// Client log macros
#define WEZ_TRACE(...)			::Wez::Log::GetClinetLogger()->trace(__VA_ARGS__)
#define WEZ_INFO(...)			::Wez::Log::GetClinetLogger()->info(__VA_ARGS__)
#define WEZ_WARN(...)			::Wez::Log::GetClinetLogger()->warn(__VA_ARGS__)
#define WEZ_ERROR(...)			::Wez::Log::GetClinetLogger()->error(__VA_ARGS__)
#define WEZ_FATAL(...)			::Wez::Log::GetClinetLogger()->fatal(__VA_ARGS__)


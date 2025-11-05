
#include "wezpch.h"
#include "Log.h"

namespace Wez {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;
	std::mutex Log::loggerMutex;

	void Log::Init()
	{
		std::lock_guard<std::mutex> lock(loggerMutex);

		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("Wez");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}
}
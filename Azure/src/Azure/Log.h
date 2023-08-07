#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Azure {
	class AZURE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Loggin Macros
//Core
#define AZ_CORE_ERROR(...) ::Azure::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AZ_CORE_WARN(...)  ::Azure::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AZ_CORE_INFO(...)  ::Azure::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AZ_CORE_TRACE(...) ::Azure::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AZ_CORE_FATAL(...) ::Azure::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//Client
#define AZ_ERROR(...) ::Azure::Log::GetClientLogger()->error(__VA_ARGS__)
#define AZ_WARN(...)  ::Azure::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AZ_INFO(...)  ::Azure::Log::GetClientLogger()->info(__VA_ARGS__)
#define AZ_TRACE(...) ::Azure::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AZ_FATAL(...) ::Azure::Log::GetClientLogger()->fatal(__VA_ARGS__)
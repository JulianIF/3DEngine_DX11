#include <DX3D/Core/Logger.h>
#include <iostream>
dx3d::Logger::Logger(LogLevel logLevel): _logLevel(logLevel)
{
}

void dx3d::Logger::log(LogLevel level, const char* message) const
{
	auto logLevelToString = [](LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Error:
			return "Error";

		case LogLevel::Warning:
			return "Warnin";

		case LogLevel::Info:
			return "Info";

		default:
			return "Unknown";
		}
	};

	if (level > _logLevel) return;
	std::clog << "[DX3D " << logLevelToString(level) << "]: " << message << "\n";
}

#pragma once
#include <DX3D/Core/Logger.h>
#include <d3d11.h>

namespace dx3d
{
	namespace GraphicLogUtils
	{
		inline void CheckShaderCompile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob)
		{
			auto errorMsg = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;
			if (FAILED(hr))
			{
				if (errorMsg)
				{
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, errorMsg);
				}
				else
				{
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, "Shader Compilatin Failed");
				}
			}

			if (errorMsg)
			{
				DX3DLog(logger, Logger::LogLevel::Warning, errorMsg)
			}
		};
	}
}

#define DX3DGraphicsLogThrowOnFail(hr, message)\
	{\
		auto res = (hr);\
		if (FAILED(res))\
		{\
			DX3DLogThrowError(message);\
		}\
	}

#define DX3DGraphicsCheckShaderCompile(hr, errorBlob)\
{\
	auto res = (hr);\
	dx3d::GraphicLogUtils::CheckShaderCompile(getLogger(), res, errorBlob);\
}
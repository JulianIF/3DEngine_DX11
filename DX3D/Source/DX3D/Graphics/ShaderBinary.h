#pragma once
#include <DX3D/Graphics/GraphicResources.h>
namespace dx3d
{
	class ShaderBinary final : public GraphicResources
	{
	public:
		ShaderBinary(const ShaderCompileDesc& sDesc, const GraphicResourcesDesc& gDesc);
		ShaderBinaryData getData() const noexcept;
		ShaderType getType() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> _blob{};
		ShaderType _type{};
	};
}

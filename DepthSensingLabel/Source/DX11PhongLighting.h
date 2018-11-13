#pragma once

/************************************************************************/
/* For shading rendering results                                        */
/************************************************************************/

#include "DX11Utils.h"
#include "DX11QuadDrawer.h"

class DX11PhongLighting
{
	public:

		static HRESULT OnD3D11CreateDevice(ID3D11Device* pd3dDevice);

		static void render(ID3D11DeviceContext* pd3dDeviceContext, ID3D11ShaderResourceView* positions, ID3D11ShaderResourceView* normals, ID3D11ShaderResourceView* colors,  ID3D11ShaderResourceView* ssaoMap, bool useMaterial, bool useSSAO);

		static void render(ID3D11DeviceContext* pd3dDeviceContext, ID3D11ShaderResourceView* positions, ID3D11ShaderResourceView* normals, ID3D11ShaderResourceView** labels, ID3D11ShaderResourceView* ssaoMap, bool useMaterial, bool useSSAO);

		//static void renderStereo(ID3D11DeviceContext* pd3dDeviceContext, ID3D11ShaderResourceView* positions, ID3D11ShaderResourceView* normals, ID3D11ShaderResourceView* colors, ID3D11ShaderResourceView** labels, ID3D11ShaderResourceView* ssaoMap, bool useMaterial, bool useSSAO);

		static void OnD3D11DestroyDevice();

		static ID3D11Texture2D* getStereoImage() 
		{
			return s_pColorsStereo;
		}
		
private:

	struct cbConstant
	{
		unsigned int useMaterial;
		unsigned int useSSAO;
		unsigned int dummy1;
		unsigned int dummy2;
	};

	static ID3D11Buffer*               s_ConstantBuffer;
	static ID3D11PixelShader*          s_PixelShaderPhong;

	static ID3D11Texture2D**           m_labelTexture;
	static ID3D11ShaderResourceView**  m_labelTextureSRV;
	static ID3D11UnorderedAccessView** m_labelTextureUAV;

	static ID3D11Texture2D*            m_coloredLabelTexture;
	static ID3D11ShaderResourceView*   m_coloredLabelTextureSRV;
	static ID3D11UnorderedAccessView*  m_coloredLabelTextureUAV;

	// Stereo
	static ID3D11Texture2D*            s_pDepthStencilStereo;
	static ID3D11DepthStencilView*     s_pDepthStencilStereoDSV;
	static ID3D11ShaderResourceView*   s_pDepthStencilStereoSRV;

	static ID3D11Texture2D*            s_pColorsStereo;
	static ID3D11ShaderResourceView*   s_pColorsStereoSRV;
	static ID3D11RenderTargetView*     s_pColorsStereoRTV;

	static unsigned int m_imageWidth;
	static unsigned int m_imageHeight;
};

#include "DirectX.h"

HRESULT DIRECTX::InitD3d(HWND hWnd)
{

	if (NULL == (pDirect3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3D失敗", "", MB_OK);
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = true;

	if (FAILED(pDirect3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &pDevice))) 
	{

		MessageBox(0, "HALモードでDIRECT３D", NULL, MB_OK);
		return E_FAIL;

	}

	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	return S_OK;

}

HRESULT DIRECTX::LoadTexture(const char* file_name, std::string key_name)
{

	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFileA(file_name, &info);

	if (FAILED(D3DXCreateTextureFromFileEx(pDevice, file_name, info.Width, info.Height, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xffffffff, NULL, NULL, &texture[key_name].p_texture)))
	{
		MessageBox(0, ("テクスチャオブジェクトの作成に失敗しました"), NULL, MB_OK);
		return E_FAIL;
	}

	D3DSURFACE_DESC desc;

	if (FAILED(texture[key_name].p_texture->GetLevelDesc(0, &desc)))
	{
		texture[key_name].p_texture->Release();
		return E_FAIL;
	}

	texture[key_name].texture_pos.x = desc.Width;
	texture[key_name].texture_pos.y = desc.Height;

	

	return S_OK;

}

void DIRECTX::Clear()
{
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
}

void DIRECTX::BiginScene()
{
	pDevice->BeginScene();
}

void DIRECTX::Draw(const char* key_name, VEC pos, VEC wh,VEC tutv, VEC twh)
{
	vertex[0] = { pos.x,		pos.y,		0.0f,1.0f,0xffffffff,tutv.x,	tutv.y };
	vertex[1] = { pos.x + wh.x	,pos.y,		0.0f,1.0f,0xffffffff,tutv.x + twh.x	,tutv.y };
	vertex[2] = { pos.x + wh.x,pos.y + wh.y,0.0f,1.0f,0xffffffff,tutv.x + twh.x	,tutv.y + twh.y };
	vertex[3] = { pos.x		,pos.y + wh.y,	0.0f,1.0f,0xffffffff,tutv.x,		tutv.y + twh.y };

	pDevice->SetTexture(0, texture[key_name].p_texture);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(CUSTOMVERTEX));

}

void DIRECTX::EndScene()
{
	pDevice->EndScene();
}

void DIRECTX::Present()
{
	pDevice->Present(0, 0, 0, 0);
}

    
DIRECTX::DIRECTX():pDirect3d(NULL), pDevice(NULL),vertex()
{
	

}

DIRECTX::~DIRECTX()
{

}

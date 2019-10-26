#include "Texture.h"

static LPDIRECT3DDEVICE9 g_D3DDevice;

bool IsCategoryRangeCheck(int category_id, int texture_id)
{
	return false;
}

bool LoadTexture(const char* file_name, int category_id, int texture_id)
{
	return false;
}

bool CreateTexture(const char* file_name, Texture* texture_data)
{
	D3DXIMAGE_INFO info;

	D3DXGetImageInfoFromFileA(file_name, &info);

	if (FAILED(D3DXCreateTextureFromFileExA(g_D3DDevice,
		file_name,
		info.Width,
		info.Height,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0x0000ff00,
		nullptr,
		nullptr,
		&texture_data->TextureData)))
	{
		return FALSE;
	}
	else
	{
		D3DSURFACE_DESC desc;

		if (FAILED(texture_data->TextureData->GetLevelDesc(0, &desc)))
		{
			texture_data->TextureData->Release();
			return FALSE;
		}
		texture_data->width = desc.Width;
		texture_data->height = desc.Height;
	}

	return 0;
}

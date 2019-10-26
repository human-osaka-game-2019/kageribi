#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

typedef struct
{
	LPDIRECT3DTEXTURE9 TextureData;
	int width;
	int height;
} Texture;

bool IsCategoryRangeCheck(int category_id, int texture_id);

bool LoadTexture(const char* file_name, int category_id, int texture_id);

bool CreateTexture(const char* file_name, Texture* texture_data);

#endif

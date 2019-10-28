#ifndef DIRECTX_HEADER
#define DIRECTX_HEADER
#include <d3d9.h>
#include <d3dx9.h>
#include <map>
#include <string>
#include "Vec.h"


struct CUSTOMVERTEX 
{
	float x, y, z;//頂点座標
	float rhw;//除算数
	DWORD dwColor;//頂点の色
	float tu, tv;//テクスチャの座標
};

struct TEXTUREDATA
{
	LPDIRECT3DTEXTURE9 p_texture;
	VEC texture_pos;
};

class DIRECTX
{
public:
	DIRECTX();
	~DIRECTX();

	HRESULT InitD3d(HWND hWnd);
	HRESULT LoadTexture(const char* file_name,std::string key_name);
	void Clear();
	void BiginScene();
	void Draw(const char* key_name, VEC pos, VEC wh, VEC tutv, VEC twh);
	void EndScene();
	void Present();

private:
	LPDIRECT3D9 pDirect3d;
	LPDIRECT3DDEVICE9 pDevice;
	std::map<std::string, TEXTUREDATA> texture;
	CUSTOMVERTEX vertex[4];
};


#endif // !DIRECTX_HEADER



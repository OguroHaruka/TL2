#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "TextureConverter.h"
#include "Windows.h"

enum Argument {
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArugument,
	__END__
};

int main(int argc, char* argv[]) {
	assert(argc >= NumArugument);

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter textureConverter;
	textureConverter.ConverteTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();
	system("pause");
	return 0;
}
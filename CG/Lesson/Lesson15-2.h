#ifndef GL_TEXTURE_LOADER
#define GL_TEXTURE_LOADER

typedef struct
{
	GLubyte *imageData; // 图像数据 (最高32bit)
	GLuint bpp;			// 每一象素的图像颜色深度
	GLuint width;		// 图像宽度
	GLuint height;		// 图像高度
	GLuint texID;		// 纹理ID
} TextureTga;

bool BuildTexture(char *filename, GLuint &texid);

#endif
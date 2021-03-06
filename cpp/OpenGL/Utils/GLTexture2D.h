#pragma once

#include <vector>

#include "GLEnv.h"  

class GLTexture2D {
public:
	GLTexture2D(GLint magFilter=GL_NEAREST, GLint minFilter=GL_NEAREST,
              GLint wrapX=GL_REPEAT, GLint wrapY=GL_REPEAT);
	~GLTexture2D();
	
  GLTexture2D(const GLTexture2D& other);
  GLTexture2D& operator=(const GLTexture2D& other);
    
	const GLint getId() const;
  void clear();
  void setEmpty(uint32_t width, uint32_t height, uint32_t componentCount, bool isFloat=false);
	void setData(const std::vector<GLubyte>& data, uint32_t width, uint32_t height, uint32_t componentCount=4);
  void setData(const std::vector<GLubyte>& data);
  void setData(const std::vector<GLfloat>& data, uint32_t width, uint32_t height, uint32_t componentCount=4);
  void setData(const std::vector<GLfloat>& data);

  uint32_t getHeight() const {return height;}
  uint32_t getWidth() const {return width;}
  uint32_t getComponentCount() const {return componentCount;}
  uint32_t getSize() const {return height*width*componentCount;}
  bool getIsFloat() const {return isFloat;}
  
  const std::vector<GLubyte>& getDataByte();
  const std::vector<GLfloat>& getDataFloat();
  
private:
	GLuint id;
	GLenum internalformat;
	GLenum format;
	GLenum type;

  GLint magFilter;
  GLint minFilter;
  GLint wrapX;
  GLint wrapY;
  std::vector<GLubyte> data;
  std::vector<GLfloat> fdata;
  uint32_t width;
  uint32_t height;
  uint32_t componentCount;
  bool isFloat;
  
  void setData(GLvoid* data, uint32_t width, uint32_t height, uint32_t componentCount, bool isFloat);
};

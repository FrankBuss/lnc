#include "GLTexture2D.h"

GLTexture2D::GLTexture2D(GLint magFilter, GLint minFilter, GLint wrapX, GLint wrapY) :
  id(0),
  internalformat(0),
  format(0),
  type(0),
  magFilter(magFilter),
  minFilter(minFilter),
  wrapX(wrapX),
  wrapY(wrapY),
  width(0),
  height(0),
  componentCount(0),
  isFloat(false)
{
  GL(glGenTextures(1, &id));
  GL(glBindTexture(GL_TEXTURE_2D, id));
  GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapX));
  GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapY));
  GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
  GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter));
}

GLTexture2D::~GLTexture2D() {
  GL(glDeleteTextures(1, &id));
}

GLTexture2D::GLTexture2D(const GLTexture2D& other) :
  GLTexture2D(other.magFilter, other.minFilter, other.wrapX, other.wrapY)
{
  if (other.height > 0 && other.width > 0) {
    if (other.isFloat)
      setData(other.fdata, other.height, other.width, other.componentCount);
    else
      setData(other.data, other.height, other.width, other.componentCount);
  }
}

GLTexture2D& GLTexture2D::operator=(const GLTexture2D& other) {
    magFilter = other.magFilter;
    minFilter = other.minFilter;
    wrapX = other.wrapX;
    wrapY = other.wrapY;
    
    GL(glBindTexture(GL_TEXTURE_2D, id));
    GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapX));
    GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapY));
    GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter));
    GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter));
    
    if (other.height > 0 && other.width > 0) {
     if (other.isFloat)
       setData(other.fdata, other.height, other.width, other.componentCount);
     else
       setData(other.data, other.height, other.width, other.componentCount);
    }
    return *this;
}

const GLint GLTexture2D::getId() const {
  return id;
}

void GLTexture2D::clear() {
  setEmpty(width,height,componentCount,isFloat);
}

void GLTexture2D::setData(const std::vector<GLubyte>& data) {
  setData(data,width,height,componentCount);
}

void GLTexture2D::setData(const std::vector<GLfloat>& data) {
  setData(data,width,height,componentCount);
}

void GLTexture2D::setEmpty(uint32_t width, uint32_t height, uint32_t componentCount, bool isFloat) {
  if (isFloat)
    setData(std::vector<GLfloat>(width*height*componentCount), width, height, componentCount);
  else
    setData(std::vector<GLubyte>(width*height*componentCount), width, height, componentCount);
}

void GLTexture2D::setData(const std::vector<GLubyte>& data, uint32_t width, uint32_t height, uint32_t componentCount) {
  if (data.size() != componentCount*width*height) {
    throw GLException{"Data size and texure dimensions do not match."};
  }
  
  this->data = data;
  setData((GLvoid*)data.data(), width, height, componentCount, false);
}

void GLTexture2D::setData(const std::vector<GLfloat>& data, uint32_t width, uint32_t height, uint32_t componentCount) {
  if (data.size() != componentCount*width*height) {
    throw GLException{"Data size and texure dimensions do not match."};
  }
  
  this->fdata = data;
  setData((GLvoid*)data.data(), width, height, componentCount, true);
}

void GLTexture2D::setData(GLvoid* data, uint32_t width, uint32_t height, uint32_t componentCount, bool isFloat) {
  this->isFloat = isFloat;
  this->width = width;
  this->height = height;
  this->componentCount = componentCount;

  GL(glBindTexture(GL_TEXTURE_2D, id));

  GL(glPixelStorei(GL_PACK_ALIGNMENT ,1));
  GL(glPixelStorei(GL_UNPACK_ALIGNMENT ,1));

  type = isFloat ? GL_FLOAT : GL_UNSIGNED_BYTE;
  switch (componentCount) {
    case 1 :
      internalformat = isFloat ? GL_R32F : GL_R8;
      format = GL_RED;
      break;
    case 2 :
      internalformat = isFloat ? GL_RG32F : GL_RG8;
      format = GL_RG;
      break;
    case 3 :
      internalformat = isFloat ? GL_RGB32F : GL_RGB8;
      format = GL_RGB;
      break;
    case 4 :
      internalformat = isFloat ? GL_RGBA32F : GL_RGBA8;
      format = GL_RGBA;
      break;
  }
  
  GL(glTexImage2D(GL_TEXTURE_2D, 0, internalformat, GLuint(width), GLuint(height), 0, format, type, data));
}


const std::vector<GLubyte>& GLTexture2D::getDataByte() {
  GL(glPixelStorei(GL_PACK_ALIGNMENT, 1));
  GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
  GL(glBindTexture(GL_TEXTURE_2D, id));
  GL(glGetTexImage(GL_TEXTURE_2D, 0, format, type, data.data()));
  return data;
}

const std::vector<GLfloat>& GLTexture2D::getDataFloat() {
  GL(glPixelStorei(GL_PACK_ALIGNMENT, 1));
  GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
  GL(glBindTexture(GL_TEXTURE_2D, id));
  GL(glGetTexImage(GL_TEXTURE_2D, 0, format, type, fdata.data()));
  return fdata;
}

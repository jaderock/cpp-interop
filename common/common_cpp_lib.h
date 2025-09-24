#pragma once

namespace PyCppInterop {

class CcLib {
public:
  CcLib() = default;
  virtual ~CcLib() = default;

  void procRGB8ToYUV420();
};

}
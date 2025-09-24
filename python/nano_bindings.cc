#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>

#include "py_cpp_lib.h"

namespace nb = nanobind;

namespace
{
  PyCppInterop::CcLib procObj;
};


int add(int a, int b) {
  procObj.procRGB8ToYUV420();
  return a + b;
}

NB_MODULE(nano_ext, m) {
  m.def("add", &add, "A function which adds two numbers");
}

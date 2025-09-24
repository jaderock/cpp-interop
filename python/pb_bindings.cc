#include <pybind11/pybind11.h>
#include "py_cpp_lib.h"

namespace py = pybind11;

namespace {
  PyCppInterop::CcLib procObj;
};

int add(int i, int j)
{
  procObj.procRGB8ToYUV420();
  return i + j;
}

PYBIND11_MODULE(pb_extension, m)
{
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("add", &add, "A function which adds two numbers");
  // ... more bindings for classes, methods, etc.
}

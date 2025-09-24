#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <iostream>

#include "common/common_cpp_lib.h"

namespace py = pybind11;

namespace {
  PyCppInterop::CcLib procObj;
};

int add(int i, int j)
{
  procObj.procRGB8ToYUV420();
  return i + j;
}

void process_numpy_array(py::array_t<double> input_array)
{
  // Request buffer information from the NumPy array
  py::buffer_info buf_info = input_array.request();

  // Access raw data pointer and dimensions
  double *data_ptr = static_cast<double *>(buf_info.ptr);
  size_t num_dimensions = buf_info.ndim;
  std::vector<size_t> shapes(buf_info.shape.begin(), buf_info.shape.end());
  std::vector<size_t> strides(buf_info.strides.begin(), buf_info.strides.end());

  // Example: Print the first element
  if (shapes.size() > 0 && shapes[0] > 0)
  {
    std::cout << "First element: " << data_ptr[0] << std::endl;
  }

  // Perform operations on the array data
  // ...
}

PYBIND11_MODULE(pb_extension, m)
{
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("add", &add, "A function which adds two numbers");
  // ... more bindings for classes, methods, etc.
  m.def("process_array", &process_numpy_array, "A function that processes a NumPy array.");
}

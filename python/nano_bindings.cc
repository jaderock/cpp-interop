#include <nanobind/nanobind.h>
#include <nanobind/ndarray.h>

#include <iostream>

#include "common/common_cpp_lib.h"

namespace nb = nanobind;

namespace
{
  PyCppInterop::CcLib procObj;
};

// Define a type alias for a CPU-resident RGB image using nanobind.
// The shape `<-1, -1, 3>` means it's a 3-channel image of any height and width.
using RGB8Image = nb::ndarray<uint8_t, nb::shape<-1, -1, 3>, nb::device::cpu>;

void process_image(RGB8Image data) {
  // You can access the raw data pointer for processing
  // nb::ndarray provides a simple interface to access metadata
  std::cout << "Processing image with nanobind" << std::endl;
  if (data.ndim() != 3) {
    throw std::runtime_error("Input array must be a 3D image.");
  }
  std::cout << "Processing image of shape (" << data.shape(0) << ", " << data.shape(1) << ")" << std::endl;
}

NB_MODULE(nano_ext, m) {
  m.def("process_image", &process_image, "process RGB8 image");
}

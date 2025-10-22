#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/instance_segmentation_doc.h"
#include "instance_segmentation_metadata.h" // Include the actual C++ header file for EmbeddingMetadata
#include "pyds.hpp"

namespace py = pybind11;

namespace pydeepstream
{
void bindinstancesegmentation (
    py::module &m); // Declare the bindings function for this submodule
}

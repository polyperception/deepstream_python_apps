#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/label_doc.h"
#include "label_metadata.h" // Include the actual C++ header file for EmbeddingMetadata
#include "pyds.hpp"

namespace py = pybind11;

namespace pydeepstream
{
void
bindlabel (py::module &m); // Declare the bindings function for this submodule
}

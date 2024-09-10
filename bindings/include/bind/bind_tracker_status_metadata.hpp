#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/tracker_status_doc.h"
#include "pyds.hpp"
#include "tracker_status.h" // Include the actual C++ header file for EmbeddingMetadata

namespace py = pybind11;

namespace pydeepstream
{
void bindtrackerstatus (
    py::module &m); // Declare the bindings function for this submodule
}

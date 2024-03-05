#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/reidembed_metadata_doc.h"
#include "pyds.hpp"
#include "reid_embeddings.h" // Include the actual C++ header file for EmbeddingMetadata

namespace py = pybind11;

namespace pydeepstream
{
void bindreidembedding (
    py::module &m); // Declare the bindings function for this submodule
}

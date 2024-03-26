#include "../../docstrings/embed_metadata_doc.h"
#include "../../docstrings/functionsdoc.h"
#include "embedding_metadata.h" // Include the actual C++ header file for EmbeddingMetadata
#include "pyds.hpp"

namespace py = pybind11;

namespace pydeepstream
{
void bindembedding (
    py::module &m); // Declare the bindings function for this submodule
}

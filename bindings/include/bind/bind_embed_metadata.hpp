#include "pyds.hpp"
#include "embedding_metadata.h"// Include the actual C++ header file for EmbeddingMetadata
#include "../../docstrings/embed_metadata_doc.h"
#include "../../docstrings/functionsdoc.h"

namespace py = pybind11;

namespace pydeepstream {
    void bindembedding(py::module &m); // Declare the bindings function for this submodule
}

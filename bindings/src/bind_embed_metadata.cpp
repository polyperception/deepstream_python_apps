#include "bind_embed_metadata.hpp"

namespace py = pybind11;

namespace pydeepstream
{

// callback function to copy custom struct to another destination custom struct
void
bindembedding (py::module &m)
{
  /* EmbeddingMetadata bindings to be used with NvDsUserMeta */
  py::class_<EmbeddingMetadata> (m, "EmbeddingMetadata",
                                 pydsdoc::embedding::EmbeddingMetadata::descr)
      .def (py::init<> ())
      // binding embedding int with EmbeddingMetadata vector
      .def_readonly ("embedding", &EmbeddingMetadata::embedding)
      // binding function to cast user_meta_data to EmbeddingMetadata
      .def (
          "cast", [] (void *data) { return (EmbeddingMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::embedding::EmbeddingMetadata::cast);

  // binding function used to allocate memory for struct in C
  // Memory ownership is maintained by bindings and only reference is passed to
  // Python

  m.attr ("NVDS_USER_META_DETECTION_EMBEDDING")
      = py::cast (NVDS_USER_META_DETECTION_EMBEDDING);
}
}

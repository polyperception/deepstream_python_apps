#include "bind_reidembed_metadata.hpp"

namespace py = pybind11;

namespace pydeepstream
{

void
bindreidembedding (py::module &m)
{
  /* EmbeddingMetadata bindings to be used with NvDsUserMeta */
  py::class_<ReIDEmbeddingMetadata> (
      m, "ReIDEmbeddingMetadata",
      pydsdoc::reidembedding::ReIDEmbeddingMetadata::descr)
      .def (py::init<> ())
      // binding embedding int with ReIDEmbeddingMetadata vector
      .def_readwrite ("embedding", &ReIDEmbeddingMetadata::embedding)
      // binding function to cast user_meta_data to ReIDEmbeddingMetadata
      .def (
          "cast", [] (void *data) { return (ReIDEmbeddingMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::reidembedding::ReIDEmbeddingMetadata::cast);

  m.attr ("NVDS_USER_META_REID_EMBEDDING")
      = py::cast (NVDS_USER_META_REID_EMBEDDING);
}
}

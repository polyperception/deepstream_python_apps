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

  // binding function used to allocate memory for struct in C
  // Memory ownership is maintained by bindings and only reference is passed to
  // Python
  m.def (
      "alloc_reidembedding_struct",
      [] (NvDsUserMeta *meta) {
        auto *mem = (ReIDEmbeddingMetadata *)g_malloc0 (
            sizeof (ReIDEmbeddingMetadata));
        meta->base_meta.copy_func
            = (NvDsMetaCopyFunc)copy_reidembedding_struct;
        meta->base_meta.release_func
            = (NvDsMetaReleaseFunc)release_reidembedding_struct;
        return mem;
      },
      py::return_value_policy::reference,
      pydsdoc::methodsDoc::alloc_reidembedding_struct);

  m.attr ("NVDS_USER_META_REID_EMBEDDING")
      = py::cast (NVDS_USER_META_REID_EMBEDDING);
}
}

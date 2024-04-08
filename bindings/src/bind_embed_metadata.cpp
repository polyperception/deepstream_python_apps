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
      .def_readwrite ("embedding", &EmbeddingMetadata::embedding)
      // binding function to cast user_meta_data to EmbeddingMetadata
      .def (
          "cast", [] (void *data) { return (EmbeddingMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::embedding::EmbeddingMetadata::cast);

  // binding function used to allocate memory for struct in C
  // Memory ownership is maintained by bindings and only reference is passed to
  // Python
  m.def (
      "alloc_embedding_struct",
      [] (NvDsUserMeta *meta) {
        auto *mem
            = (EmbeddingMetadata *)g_malloc0 (sizeof (EmbeddingMetadata));
        meta->base_meta.copy_func = (NvDsMetaCopyFunc)copy_embedding_struct;
        meta->base_meta.release_func
            = (NvDsMetaReleaseFunc)release_embedding_struct;
        return mem;
      },
      py::return_value_policy::reference,
      pydsdoc::methodsDoc::alloc_embedding_struct);

  m.attr ("NVDS_USER_META_DETECTION_EMBEDDING")
      = py::cast (NVDS_USER_META_DETECTION_EMBEDDING);
}
}

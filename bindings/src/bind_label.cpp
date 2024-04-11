#include "bind_label.hpp"

namespace py = pybind11;

namespace pydeepstream
{

// callback function to copy custom struct to another destination custom struct
void
bindlabel (py::module &m)
{
  /* EmbeddingMetadata bindings to be used with NvDsUserMeta */
  py::class_<Label> (m, "Label")
      .def (py::init<> ())
      .def_readwrite ("classifier_id", &Label::classifier_id)
      .def_readwrite ("nb_ids", &Label::nb_ids)
      .def_readwrite ("label_id", &Label::label_id)
      .def_readwrite ("score", &Label::score)
      .def_readwrite ("scores", &Label::scores);

  py::class_<LabelsMetadata> (m, "LabelsMetadata",
                              pydsdoc::label::LabelsMetadata::descr)
      .def (py::init<> ())
      // binding embedding int with EmbeddingMetadata vector
      .def_readwrite ("labels", &LabelsMetadata::labels)
      // binding function to cast user_meta_data to EmbeddingMetadata
      .def (
          "cast", [] (void *data) { return (LabelsMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::label::LabelsMetadata::cast);

  // binding function used to allocate memory for struct in C
  // Memory ownership is maintained by bindings and only reference is passed to
  // Python
  m.def (
      "alloc_label_struct",
      [] (NvDsUserMeta *meta) {
        auto *mem = (LabelsMetadata *)g_malloc0 (sizeof (LabelsMetadata));
        meta->base_meta.copy_func = (NvDsMetaCopyFunc)copy_label_struct;
        meta->base_meta.release_func
            = (NvDsMetaReleaseFunc)release_label_struct;
        return mem;
      },
      py::return_value_policy::reference,
      pydsdoc::methodsDoc::alloc_embedding_struct);

  m.attr ("NVDS_USER_META_LABEL") = py::cast (NVDS_USER_META_LABEL);
}
}

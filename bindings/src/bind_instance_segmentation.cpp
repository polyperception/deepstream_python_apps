#include "bind_instance_segmentation.hpp"

namespace py = pybind11;

namespace pydeepstream
{

void
bindinstancesegmentation (py::module &m)
{
  /* EmbeddingMetadata bindings to be used with NvDsUserMeta */
  py::class_<InstanceSegmentationMetadata> (
      m, "InstanceSegmentationMetadata",
      pydsdoc::instancesegmentation::InstanceSegmentationMetadata::descr)
      .def (py::init<> ())
      // binding embedding int with InstanceSegmentationMetadata vector
      .def_readwrite ("polygon", &InstanceSegmentationMetadata::polygon)
      .def_readwrite ("area", &InstanceSegmentationMetadata::class_ids)
      // binding function to cast user_meta_data to ReIDEmbeddingMetadata
      .def (
          "cast",
          [] (void *data) { return (InstanceSegmentationMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::instancesegmentation::InstanceSegmentationMetadata::cast);

  m.attr ("NVDS_USER_META_INSTANCE_SEGMENTATION")
      = py::cast (NVDS_USER_META_INSTANCE_SEGMENTATION);
}
}

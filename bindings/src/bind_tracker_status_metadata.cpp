#include "bind_tracker_status_metadata.hpp"

namespace py = pybind11;

namespace pydeepstream
{

void
bindtrackerstatus (py::module &m)
{
  // Bind the TrackerStatus enum
  py::enum_<TrackerStatus> (m, "TrackerStatus")
      .value ("SOLVED", TrackerStatus::SOLVED)
      .value ("UNSOLVED", TrackerStatus::UNSOLVED)
      .export_values ();

  // Bind the TrackerStatusMetadata struct
  py::class_<TrackerStatusMetadata> (m, "TrackerStatusMetadata",
                                     "Metadata for tracker status")
      .def (py::init<> ())
      .def_readwrite ("status", &TrackerStatusMetadata::status)
      .def (
          "cast", [] (void *data) { return (TrackerStatusMetadata *)data; },
          py::return_value_policy::reference,
          "Cast user_meta_data to TrackerStatusMetadata");

  m.attr ("NVDS_USER_META_TRACKER_STATUS")
      = py::cast (NVDS_USER_META_TRACKER_STATUS);
}

}

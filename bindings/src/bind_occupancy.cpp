#include "bind_occupancy.hpp"

namespace py = pybind11;

namespace pydeepstream
{

void
bindoccupancy (py::module &m)
{
  /* OccupancyMetadata bindings to be used with NvDsFrameMeta */
  py::class_<OccupancyMetadata> (
      m, "OccupancyMetadata",
      pydsdoc::occupancy::OccupancyMetadata::descr)
      .def (py::init<> ())
      .def_readwrite ("occupancy", &OccupancyMetadata::occupancy)
      .def (
          "cast",
          [] (void *data) { return (OccupancyMetadata *)data; },
          py::return_value_policy::reference,
          pydsdoc::occupancy::OccupancyMetadata::cast);

  m.attr ("NVDS_USER_META_OCCUPANCY")
      = py::cast (NVDS_USER_META_OCCUPANCY);
}
}

#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/occupancy_doc.h"
#include "occupancy.h" // Include the actual C++ header file for OccupancyMetadata
#include "pyds.hpp"

namespace py = pybind11;

namespace pydeepstream
{
void bindoccupancy (
    py::module &m);
}

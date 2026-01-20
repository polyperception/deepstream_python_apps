#include "../../docstrings/functionsdoc.h"
#include "../../docstrings/occupancydoc.h"
#include "occupancy.h" // Include the actual C++ header file for OccupancyMetadata
#include "pyds.hpp"

namespace py = pybind11;

namespace pydeepstream
{
void bindoccupancy (
    py::module &m);
}

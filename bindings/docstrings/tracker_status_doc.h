#pragma once

namespace pydsdoc
{
namespace trackerstatus
{
namespace TrackinStatus
{
constexpr const char* descr = R"pyds(
    Enum representing the tracking status of a frame.

    :cvar SOLVED: Indicates that the frame has been successfully tracked and solved.
    :cvar UNSOLVED: Indicates that the frame has not been solved or tracking was unsuccessful.
)pyds";
}

namespace TrackerStatusMetadata
{
constexpr const char* descr = R"pyds(
    Metadata structure for storing tracker status information.

    :ivar status: :class:`TrackinStatus`, The current tracking status of the frame.
)pyds";

constexpr const char* cast = R"pyds(
    Cast given object/data to :class:`TrackerStatusMetadata`.

    :param data: The data to cast.
    :return: A reference to the casted :class:`TrackerStatusMetadata` object.

    Usage: pyds.TrackerStatusMetadata.cast(data)
)pyds";
}

namespace NVDS_USER_META_TRACKER_STATUS
{
constexpr const char* descr = R"pyds(
    Custom metadata type for tracker status.

    This constant defines a custom metadata type for use with NvDsUserMeta to represent tracker status information.
)pyds";
}

} // namespace trackerstatus
} // namespace pydsdoc

/*
 * SPDX-FileCopyrightText: Copyright (c) 2021-2022 NVIDIA CORPORATION &
 * AFFILIATES. All rights reserved. SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

namespace pydsdoc
{
namespace instancesegmentation
{
namespace InstanceSegmentationMetadata
{
constexpr const char *descr = R"pyds(
                 Holds polygon and area information of the instance segmentation. 
                 Polygon is normalized values to the entier image.
 
                 :ivar polygon: *vector<int>*, normalized polygon values)pyds)
                 :ivar area: *vector<int>*, area values)pyds";

constexpr const char *cast
    = R"pyds(cast given object/data to :class:`InstanceSegmentationMetadata`, call pyds.InstanceSegmentationMetadata.cast(data))pyds";
}
}
}

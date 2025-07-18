# SPDX-FileCopyrightText: Copyright (c) 2021-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Setting values not set by user
function(check_variable_set variable_name default_value)
        if (NOT DEFINED ${variable_name})
                set(${variable_name} ${default_value} PARENT_SCOPE)
        endif()
endfunction()

check_variable_set(PYTHON_MAJOR_VERSION 3)
check_variable_set(PYTHON_MINOR_VERSION 10)

check_variable_set(DS_PATH "/opt/nvidia/deepstream/deepstream")
if (DEFINED IS_SBSA)
	message("IS_SBSA is set. Enabling definitions for ARM_SBSA")
	add_compile_definitions(IS_SBSA)
endif()

# Checking values are allowed
macro(check_variable_allowed var_name var_list)
        if(NOT ${var_name} IN_LIST ${var_list})
                message(FATAL_ERROR "${var_name} must be one of ${${var_list}}")
        endif()
endmacro()
set(PYTHON_MAJVERS_ALLOWED 3)
check_variable_allowed(PYTHON_MAJOR_VERSION PYTHON_MAJVERS_ALLOWED)
set(PYTHON_MINVERS_ALLOWED 10)
check_variable_allowed(PYTHON_MINOR_VERSION PYTHON_MINVERS_ALLOWED)

# Setting C++ values
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")

# Setting python build versions
set(PYTHON_VERSION ${PYTHON_MAJOR_VERSION}.${PYTHON_MINOR_VERSION})
set(PIP_WHEEL pyds-1.1.11-py3-none-${PIP_PLATFORM}.whl)

# Describing pyds build
project(pyds DESCRIPTION "Python bindings for Deepstream")
add_compile_options(-Wall -Wextra -pedantic -O3)

include_directories(
        include/
        ${DS_PATH}/sources/includes/
        include/bind
        include/nvds
        3rdparty/pybind11/include/pybind11/
        3rdparty/pybind11/include/
        /usr/include/python${PYTHON_VERSION}
        /usr/include/gstreamer-1.0
        /usr/include/glib-2.0
        /usr/lib/aarch64-linux-gnu/glib-2.0/include/
        /usr/lib/x86_64-linux-gnu/glib-2.0/include
        /usr/app/gst-plugins/gst-p12n/subprojects/global-utils/include/metadata/
        )

add_library(pyds SHARED src/pyds.cpp src/utils.cpp src/bindanalyticsmeta.cpp
            src/bindfunctions.cpp src/bindgstnvdsmeta.cpp
            src/bindmeta360.cpp src/bindnvbufsurface.cpp src/bindnvdsinfer.cpp
            src/bindnvdsmeta.cpp src/bindnvosd.cpp src/bindopticalflow.cpp
            src/bindschema.cpp src/bindtrackermeta.cpp src/custom_binding/bindcustom.cpp
            src/bind_reidembed_metadata.cpp src/bind_embed_metadata.cpp
            src/bind_label.cpp src/bind_tracker_status_metadata.cpp)

set_target_properties(pyds PROPERTIES PREFIX "")
set_target_properties(pyds PROPERTIES OUTPUT_NAME "pyds")

set(PYTHON_LIB python${PYTHON_VERSION})

target_link_libraries(pyds pthread dl ${PYTHON_LIB} gstreamer-1.0 glib-2.0)

# Checking deepstream shared libraries and linking them
function(add_ds_lib libname)
        set(libpath "${DS_PATH}/lib/lib${libname}.so")
        if(NOT EXISTS ${libpath})
                message(FATAL_ERROR "Missing lib${libname}.so at ${libpath}\n"
                        "please make sure that deepstream is installed")
        endif()
        add_library(${libname} SHARED IMPORTED)
        set_target_properties(${libname} PROPERTIES
                IMPORTED_LOCATION ${libpath})
        target_link_libraries(pyds ${libname})
endfunction()

foreach(nvds_lib nvds_osd nvds_meta nvds_infer nvdsgst_meta nvbufsurface nvbufsurftransform nvdsgst_helper nvdsgst_customhelper nvds_batch_jpegenc)
        add_ds_lib(${nvds_lib})
endforeach()
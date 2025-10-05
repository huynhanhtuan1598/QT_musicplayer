# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appass_qt_01_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appass_qt_01_autogen.dir\\ParseCache.txt"
  "appass_qt_01_autogen"
  )
endif()

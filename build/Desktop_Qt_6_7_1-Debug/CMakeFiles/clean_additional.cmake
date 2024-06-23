# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SubbuStore_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SubbuStore_autogen.dir/ParseCache.txt"
  "SubbuStore_autogen"
  )
endif()

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/NixRar_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/NixRar_autogen.dir/ParseCache.txt"
  "NixRar_autogen"
  )
endif()

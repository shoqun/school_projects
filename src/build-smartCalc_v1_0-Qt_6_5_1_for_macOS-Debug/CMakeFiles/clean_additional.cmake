# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/smartCalc_v1_0_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/smartCalc_v1_0_autogen.dir/ParseCache.txt"
  "smartCalc_v1_0_autogen"
  )
endif()

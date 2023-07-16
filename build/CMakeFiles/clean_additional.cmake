# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ImageViewerQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ImageViewerQt_autogen.dir/ParseCache.txt"
  "ImageViewerQt_autogen"
  )
endif()

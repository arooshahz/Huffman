# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Huffman_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Huffman_autogen.dir\\ParseCache.txt"
  "Huffman_autogen"
  )
endif()

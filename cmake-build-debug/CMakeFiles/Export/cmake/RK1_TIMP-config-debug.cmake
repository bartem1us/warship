#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "RK1_TIMP" for configuration "Debug"
set_property(TARGET RK1_TIMP APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(RK1_TIMP PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libRK1_TIMP.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS RK1_TIMP )
list(APPEND _IMPORT_CHECK_FILES_FOR_RK1_TIMP "${_IMPORT_PREFIX}/lib/libRK1_TIMP.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

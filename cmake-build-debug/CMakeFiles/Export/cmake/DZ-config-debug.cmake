#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "DZ" for configuration "Debug"
set_property(TARGET DZ APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(DZ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libDZ.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS DZ )
list(APPEND _IMPORT_CHECK_FILES_FOR_DZ "${_IMPORT_PREFIX}/lib/libDZ.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

# libbarchive - Archive utility library for NixRar

# Qt6 dependency (Core for QString, QFileInfo, etc.)
qt6_core_dep = dependency('qt6', modules : ['Core'], required : true)

# Library sources
libbarchive_sources = [
  'src/archive_utils.cpp'
]

# Include directories
libbarchive_inc = include_directories('include')

# Create static library
libbarchive_lib = static_library('barchive',
  libbarchive_sources,
  include_directories : libbarchive_inc,
  dependencies : qt6_core_dep,
  cpp_args : [
    '-Wall',
    '-Wextra',
    '-std=c++23'
  ],
  install : false  # Don't install by default, only for main project use
)

# Create dependency object for main project
libbarchive_dep = declare_dependency(
  link_with : libbarchive_lib,
  include_directories : libbarchive_inc,
  dependencies : qt6_core_dep
)
project('NixRar', 'cpp',
  version : '0.0.1',
  default_options : [
    'cpp_std=c++23',
    'warning_level=2',
    'werror=false'
  ]
)

# Qt6 dependencies
qt6 = import('qt6')
qt6_dep = dependency('qt6', modules : ['Core', 'Gui', 'Widgets'], required : true)

# LibArchive dependency
libarchive_dep = dependency('libarchive', required : true)

# Add libbarchive library subdirectory
subdir('libs/libbarchive')

# Process Qt resources and UI files
qt6_resources = qt6.compile_resources(
  sources : 'NixRar.qrc',
  name : 'nixrar_resources'
)

qt6_ui = qt6.compile_ui(
  sources : 'MainWindow.ui'
)

# Process Qt MOC files
qt6_moc = qt6.compile_moc(
  headers : [
    'MainWindow.h',
    'FileExplorer.h'
  ],
  sources : [
    'MainWindow.cpp',
    'FileExplorer.cpp'
  ]
)

# Source files
sources = [
  'main.cpp',
  'MainWindow.cpp',
  'FileExplorerModel.cpp',
  'Archive.cpp',
  'FileExplorer.cpp'
]

# Headers (for IDE support)
headers = [
  'MainWindow.h',
  'FileExplorerModel.h',
  'Archive.h',
  'FileExplorer.h'
]

# Create executable
nixrar_exe = executable('NixRar',
  sources,
  qt6_resources,
  qt6_ui,
  qt6_moc,
  dependencies : [
    qt6_dep,
    libarchive_dep,
    libbarchive_dep
  ],
  install : true,
  install_dir : get_option('bindir')
)

# Optional: Set up install for desktop integration (Linux)
if host_machine.system() == 'linux'
  # Desktop file installation would go here if created
  # install_data('nixrar.desktop', install_dir : 'share/applications')
  # install_data('icons/nixrar.png', install_dir : 'share/pixmaps')
endif

# Print configuration summary
summary({
  'Qt6 version' : qt6_dep.version(),
  'LibArchive found' : libarchive_dep.found(),
  'C++ standard' : get_option('cpp_std'),
  'Install directory' : get_option('prefix') / get_option('bindir')
}, section : 'Configuration')
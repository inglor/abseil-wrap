project('abseil-wrap', 'cpp',
        version : '0',
        meson_version : '>=0.55',
        default_options : [
          'cpp_std=c++17',
        ])

cpp = meson.get_compiler('cpp')
add_project_arguments('-DPROJECT_VERSION="@0@"'.format(meson.project_version()), language : 'cpp')
add_project_arguments(cpp.get_supported_arguments(['-ffunction-sections', '-fdata-sections', 
'-Wnon-virtual-dtor']), language : 'cpp')
add_project_link_arguments(cpp.get_supported_link_arguments(['-Wl,--gc-sections']), language : 'cpp')

abseil_proj = subproject('abseil-cpp', default_options : [
    'default_library=static',
  ])
abseil = declare_dependency(
  dependencies : [
    abseil_proj.get_variable('absl_container_dep'),
    abseil_proj.get_variable('absl_status_dep'),
    abseil_proj.get_variable('absl_strings_dep'),
    abseil_proj.get_variable('absl_time_dep'),
  ],
  include_directories : [
    abseil_proj.get_variable('absl_include_dir'),
  ])

executable('main', files('src/main.cc'), dependencies : [abseil], install : true)

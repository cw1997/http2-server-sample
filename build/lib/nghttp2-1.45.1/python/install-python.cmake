get_filename_component(rootdir "$ENV{DESTDIR}" ABSOLUTE)
if(rootdir STREQUAL "")
  set(rootdir /)
endif()
execute_process(
  COMMAND "/usr/bin/python" setup.py install
    --skip-build
    --root=${rootdir} --prefix=${CMAKE_INSTALL_PREFIX}
  WORKING_DIRECTORY "/home/cw1997/github/cw1997/http2-server-sample/build/lib/nghttp2-1.45.1/python"
)

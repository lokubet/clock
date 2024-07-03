message("-- Linking SDL")
add_library(dll_lib  libjpeg-9.dll libpng16-16.dll libtiff-5.dll libwebp-7.dll zlib1.dll )
set_target_properties(dll_lib PROPERTIES LINKER_LANGUAGE C)

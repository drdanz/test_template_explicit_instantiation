cmake_minimum_required(VERSION 3.12)

project(test_template_explicit_instantiation
        LANGUAGES CXX
        VERSION 1.0.0)


include(GNUInstallDirs)
include(GenerateExportHeader)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}")

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()


set(_libs)


add_library(foo SHARED)
generate_export_header(foo)
target_sources(foo PRIVATE foo.h
                           foo-inl.h
                           foo.cpp)
target_include_directories(foo PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
                               INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(foo PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(foo PRIVATE cxx_std_17)
list(APPEND _libs foo)

if(NOT MSVC)
add_library(foo_extend SHARED)
generate_export_header(foo_extend)
target_sources(foo_extend PRIVATE foo_extend.h
                                  foo_extend.cpp)
target_include_directories(foo_extend PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
                                      INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                      PRIVATE $<TARGET_PROPERTY:foo,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_options(foo_extend PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(foo_extend PRIVATE cxx_std_17)
list(APPEND _libs foo_extend)


add_library(foo_hack SHARED)
generate_export_header(foo_hack)
target_sources(foo_hack PRIVATE foo_hack.h
                                foo_hack.cpp)
target_include_directories(foo_hack PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
                                    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                                    PRIVATE $<TARGET_PROPERTY:foo,INTERFACE_INCLUDE_DIRECTORIES>)
target_compile_options(foo_hack PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(foo_hack PRIVATE cxx_std_17)
list(APPEND _libs foo_hack)
endif()


add_library(bar SHARED)
generate_export_header(bar)
target_sources(bar PRIVATE bar.h
                           bar-inl.h
                           bar.cpp)
target_include_directories(bar PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
                               INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(bar PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(bar PRIVATE cxx_std_17)
list(APPEND _libs bar)



add_library(zot SHARED)
generate_export_header(zot)
target_sources(zot PRIVATE zot.h
                           zot.cpp)
target_link_libraries(zot PUBLIC foo bar)
target_include_directories(zot PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
                               INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(zot PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(zot PRIVATE cxx_std_17)
list(APPEND _libs zot)


add_executable(main)
target_sources(main PRIVATE main.cpp)
target_link_libraries(main PRIVATE ${_libs})
target_compile_options(main PRIVATE
     $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
          -Wall -Wextra -fdiagnostics-color=always>
     $<$<CXX_COMPILER_ID:MSVC>:
          /W4>)
target_compile_features(main PRIVATE cxx_std_17)

add_test(NAME main_test
         COMMAND main)

if(NOT MSVC)
add_test(NAME nm
         COMMAND nm -ACD --defined-only ${CMAKE_CURRENT_BINARY_DIR}/lib/*.so)
endif()

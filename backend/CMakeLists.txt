set(CMAKE_POLICY_DEFAULT_CMP0000 OLD)
cmake_minimum_required(VERSION 4.2.3)
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)

project(Harmony)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

include(FetchContent)

FetchContent_Declare(
  datachannel
  GIT_REPOSITORY https://github.com/paullouisageneau/libdatachannel.git
  GIT_TAG v0.21.2
  GIT_PROGRESS TRUE
  # Keep the patch to stop CMake from crashing on re-run
  PATCH_COMMAND sed -i "255s|^|#|" deps/libsrtp/CMakeLists.txt
)

FetchContent_Declare(
  json 
  GIT_REPOSITORY https://github.com/nlohmann/json.git 
  GIT_TAG v3.11.3
  GIT_PROGRESS TRUE
)

FetchContent_Declare(
  stduuid 
  GIT_REPOSITORY https://github.com/mariusbancila/stduuid.git
  GIT_TAG v1.2.3
  GIT_PROGRESS TRUE
)

# Configuration for libdatachannel
set(LIBDATACHANNEL_STATIC ON CACHE INTERNAL "")
set(NO_EXAMPLES ON CACHE INTERNAL "")
set(NO_TESTS ON CACHE INTERNAL "")
set(ENABLE_OPENSSL ON CACHE BOOL "" FORCE)

# NEW: Inject the version macro so the C compiler doesn't freak out
add_compile_definitions(PACKAGE_VERSION="2.5.0")

FetchContent_MakeAvailable(datachannel json stduuid)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Build the executable using the discovered files
add_executable(harmony_server ${SOURCES})
target_link_libraries(harmony_server PRIVATE datachannel nlohmann_json::nlohmann_json stduuid)

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for datachannel")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/home/computer/Code/harmony/backend/build/_deps/datachannel-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[sed]====] [====[-i]====] [====[255s|^|#|]====] [====[deps/libsrtp/CMakeLists.txt]====]
)

endblock()

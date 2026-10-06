# Install script for directory: /home/computer/Code/harmony/backend/build/_deps/datachannel-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdatachannel.so.0.21.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdatachannel.so.0.21"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/libdatachannel.so.0.21.2"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/libdatachannel.so.0.21"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdatachannel.so.0.21.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libdatachannel.so.0.21"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/libdatachannel.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/rtc" TYPE FILE FILES
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/candidate.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/channel.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/configuration.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/datachannel.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/description.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/mediahandler.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtcpreceivingsession.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/common.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/global.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/message.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/frameinfo.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/peerconnection.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/reliability.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtc.h"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtc.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtp.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/track.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/websocket.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/websocketserver.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtppacketizationconfig.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtcpsrreporter.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtppacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtpdepacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/h264rtppacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/h264rtpdepacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/nalunit.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/h265rtppacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/h265nalunit.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/av1rtppacketizer.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/nalunit.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/rtcpnackresponder.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/utils.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/plihandler.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/pacinghandler.hpp"
    "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/include/rtc/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel/LibDataChannelTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel/LibDataChannelTargets.cmake"
         "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/CMakeFiles/Export/32c821eb1e7b36c3a3818aec162f7fd2/LibDataChannelTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel/LibDataChannelTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel/LibDataChannelTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel" TYPE FILE FILES "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/CMakeFiles/Export/32c821eb1e7b36c3a3818aec162f7fd2/LibDataChannelTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel" TYPE FILE FILES "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/CMakeFiles/Export/32c821eb1e7b36c3a3818aec162f7fd2/LibDataChannelTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel" TYPE FILE FILES "/home/computer/Code/harmony/backend/build/_deps/datachannel-src/cmake/LibDataChannelConfig.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/LibDataChannel" TYPE FILE FILES "/home/computer/Code/harmony/backend/build/LibDataChannelConfigVersion.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.

endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/computer/Code/harmony/backend/build/_deps/datachannel-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()

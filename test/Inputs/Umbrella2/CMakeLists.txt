set(SOURCES
  Umbrella2.m
  )
set(PUBLIC_HEADERS
  Headers/AAA.h
  Headers/SpecialUmbrella.h
  )
set(PRIVATE_HEADERS
  PrivateHeaders/AAA.h
  PrivateHeaders/SpecialPrivateUmbrella.h
  )

add_library(Umbrella2
  SHARED
  ${PUBLIC_HEADERS}
  ${PRIVATE_HEADERS}
  ${SOURCES}
  )

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -arch x86_64")
set(CMAKE_SHARED_LINKER_FLAGS "-current_version 1 -compatibility_version 1")

set_target_properties(Umbrella2
  PROPERTIES
  FRAMEWORK TRUE
  FRAMEWORK_VERSION A
  PUBLIC_HEADER "${PUBLIC_HEADERS}"
  PRIVATE_HEADER "${PRIVATE_HEADERS}"
  INSTALL_NAME_DIR /System/Library/Frameworks
  VERSION 1
  SOVERSION 1
  )

install(TARGETS Umbrella2
  FRAMEWORK DESTINATION System/Library/Frameworks
  )

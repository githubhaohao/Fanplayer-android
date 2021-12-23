# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
set(BUILD_LIB_NAME fanplayer_jni)
set(libs "${CMAKE_SOURCE_DIR}/libs")

include_directories(
avkcpdemuxer
ffrdpdemuxer
        src
        include
        utils
)

link_directories(
        ${libs}
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

find_library( # Sets the name of the path variable.
        GLESv2-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        GLESv2 )

set(LINK_LIB_LIST
        avformat
        avcodec
        avdevice
        avfilter
        swresample
        swscale
        avutil
        ssl
        crypto
        soundtouch
        stlport_static
        )

set(LINK_LOCAL_LIB_LIST
        ${log-lib}
        z
        android
        GLESv2
)

add_library( # Sets the name of the library.
        ${BUILD_LIB_NAME}

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/ffplayer.c
        src/ffrender.c
        src/pktqueue.c
        src/snapshot.c
        src/recorder.c
        src/datarate.c
        src/vdev-cmn.c
        src/adev-android.cpp
        src/vdev-android.cpp
        src/fanplayer_jni.cpp
        utils/GLUtils.cpp
        avkcpdemuxer/ikcp.c
        avkcpdemuxer/ringbuf.c
        avkcpdemuxer/avkcpc.c
        avkcpdemuxer/avkcpd.c
        ffrdpdemuxer/ffrdp.c
        ffrdpdemuxer/ffrdpc.c
        ffrdpdemuxer/ffrdpd.c
        )

#add_library(stlport_static STATIC IMPORTED )
#set_target_properties(stlport_static PROPERTIES IMPORTED_LOCATION "${CMAKE_ANDROID_NDK}/sources/cxx-stl/stlport/libs/${TARGET_ARCH_ABI}/libstlport_static.a")
#add_library(stlport_static STATIC IMPORTED )
#set_target_properties(stlport_static PROPERTIES IMPORTED_LOCATION "${libs}/libstlport_static.a")
#
#add_library(avformat STATIC IMPORTED )
#set_target_properties(avformat PROPERTIES IMPORTED_LOCATION "${libs}/libavformat.a")
#
#add_library(avcodec STATIC IMPORTED )
#set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION "${libs}/libavcodec.a")
#
#add_library(avdevice STATIC IMPORTED )
#set_target_properties(avdevice PROPERTIES IMPORTED_LOCATION "${libs}/libavdevice.a")
#
#add_library(avfilter STATIC IMPORTED )
#set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION "${libs}/libavfilter.a")
#
#add_library(swresample STATIC IMPORTED )
#set_target_properties(swresample PROPERTIES IMPORTED_LOCATION "${libs}/libswresample.a")
#
#add_library(swscale STATIC IMPORTED )
#set_target_properties(swscale PROPERTIES IMPORTED_LOCATION "${libs}/libswscale.a")
#
#add_library(avutil STATIC IMPORTED )
#set_target_properties(avutil PROPERTIES IMPORTED_LOCATION "${libs}/libavutil.a")
#
#add_library(x264 STATIC IMPORTED )
#set_target_properties(x264 PROPERTIES IMPORTED_LOCATION "${libs}/libx264.a")
#
#add_library(soundtouch STATIC IMPORTED )
#set_target_properties(soundtouch PROPERTIES IMPORTED_LOCATION "${libs}/libsoundtouch.a")

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

#target_link_libraries( # Specifies the target library.
#        ${BUILD_LIB_NAME}
#
#                       # Links the target library to the log library
#                       # included in the NDK.
#                       avformat
#                       avcodec
#                       avdevice
#                       avfilter
#                       swresample
#                       swscale
#                       avutil
#                       x264
#                       soundtouch
#                       ${log-lib}
#                       z
#                       android
#                       stlport_static
#                       )

target_link_libraries( # Specifies the target library.
        ${BUILD_LIB_NAME}

        # Links the target library to the log library
        # included in the NDK.
        ${LINK_LIB_LIST}
        ${LINK_LOCAL_LIB_LIST}
        )


TEMPLATE = subdirs
CONFIG   += ordered

SUBDIRS += flightgear \
           geoclue \
#           gpsd \
           qtpositioning \
#           wlocate

DISTFILES += \
    CMakeLists.txt

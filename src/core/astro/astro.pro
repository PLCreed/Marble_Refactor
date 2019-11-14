CONFIG -= qt

TEMPLATE = lib
DEFINES += ASTRO_LIBRARY

DEFINES += _USE_MATH_DEFINES # 解决 #include <cmath> 找不到M_PI

CONFIG(debug, debug|release) {
    TARGET = astrod
}
CONFIG(release, debug|release) {
    TARGET = astro
}

SOURCES += \
    astr2lib.cpp \
    astrolib.cpp \
    attlib.cpp \
    eclsolar.cpp \
    planetarySats.cpp \
    solarsystem.cpp

HEADERS += \
    astr2lib.h \
    astrolib.h \
    astrolib_export.h \
    attlib.h \
    eclsolar.h \
    planetarySats.h \
    solarsystem.h

DISTFILES += \
    CMakeLists.txt \
    docs/README \
    docs/SolarSystem.pdf

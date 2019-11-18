### 项目配置
#######################################################################################################################
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

#DESTDIR = ../../../bin

### 源代码
#######################################################################################################################
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

### 部署
########################################################################################################################
target.path += $$DEBUG_DESDIR/

# Debug
interactive_libs_debug.files += $$OUT_PWD/debug/astrod.dll
interactive_libs_debug.path += $$DEBUG_DESDIR/
# Release
interactive_libs_release.files += $$OUT_PWD/release/astro.dll
interactive_libs_release.path += $$DEBUG_DESDIR/

CONFIG(debug, debug|release) {
    INSTALLS += interactive_libs_debug
}
CONFIG(release, debug|release) {
    INSTALLS += interactive_libs_release
}

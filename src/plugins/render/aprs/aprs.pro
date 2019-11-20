### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

QT += serialport

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = aprsd
}
CONFIG(release, debug|release) {
    TARGET = aprs
}

### 源代码\n#######################################################################################################################
SOURCES += \
    AprsFile.cpp \
    AprsGatherer.cpp \
    AprsObject.cpp \
    AprsPlugin.cpp \
    AprsSource.cpp \
    AprsTCPIP.cpp \
    AprsTTY.cpp \
    GeoAprsCoordinates.cpp

HEADERS += \
    aprsconfig.h.in \
    AprsFile.h \
    AprsGatherer.h \
    AprsObject.h \
    AprsPlugin.h \
    AprsSource.h \
    AprsTCPIP.h \
    AprsTTY.h \
    GeoAprsCoordinates.h

FORMS += \
    AprsConfigWidget.ui

### 部署
#######################################################################################################################
target.path += $$DEBUG_DESDIR/

# Debug
interactive_libs_debug.files += $$OUT_PWD/debug/*.dll
interactive_libs_debug.path += $$DEBUG_DESDIR/plugins
# Release
interactive_libs_release.files += $$OUT_PWD/release/*.dll
interactive_libs_release.path += $$DEBUG_DESDIR/plugins

CONFIG(debug, debug|release) {
    INSTALLS += interactive_libs_debug
}
CONFIG(release, debug|release) {
    INSTALLS += interactive_libs_release
}

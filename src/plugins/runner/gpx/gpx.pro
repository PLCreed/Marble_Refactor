### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

QT += testlib

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = gpxd
}
CONFIG(release, debug|release) {
    TARGET = gpx
}

INCLUDEPATH += $$PWD/handlers

### 源代码\n#######################################################################################################################
SOURCES += \
    GpxParser.cpp \
    GpxPlugin.cpp \
    GpxRunner.cpp \
    handlers/GPXcmtTagHandler.cpp \
    handlers/GPXdescTagHandler.cpp \
    handlers/GPXElementDictionary.cpp \
    handlers/GPXeleTagHandler.cpp \
    handlers/GPXextensionsTagHandler.cpp \
    handlers/GPXgpxTagHandler.cpp \
    handlers/GPXhrTagHandler.cpp \
    handlers/GPXlinkTagHandler.cpp \
    handlers/GPXnameTagHandler.cpp \
    handlers/GPXrteptTagHandler.cpp \
    handlers/GPXrteTagHandler.cpp \
    handlers/GPXtimeTagHandler.cpp \
    handlers/GPXTrackPointExtensionTagHandler.cpp \
    handlers/GPXtrkptTagHandler.cpp \
    handlers/GPXtrksegTagHandler.cpp \
    handlers/GPXtrkTagHandler.cpp \
    handlers/GPXtypeTagHandler.cpp \
    handlers/GPXurlnameTagHandler.cpp \
    handlers/GPXurlTagHandler.cpp \
    handlers/GPXwptTagHandler.cpp \
    tests/TestTrack.cpp

HEADERS += \
    GpxParser.h \
    GpxPlugin.h \
    GpxRunner.h \
    handlers/GPXcmtTagHandler.h \
    handlers/GPXdescTagHandler.h \
    handlers/GPXElementDictionary.h \
    handlers/GPXeleTagHandler.h \
    handlers/GPXextensionsTagHandler.h \
    handlers/GPXgpxTagHandler.h \
    handlers/GPXhrTagHandler.h \
    handlers/GPXlinkTagHandler.h \
    handlers/GPXnameTagHandler.h \
    handlers/GPXrteptTagHandler.h \
    handlers/GPXrteTagHandler.h \
    handlers/GPXtimeTagHandler.h \
    handlers/GPXTrackPointExtensionTagHandler.h \
    handlers/GPXtrkptTagHandler.h \
    handlers/GPXtrksegTagHandler.h \
    handlers/GPXtrkTagHandler.h \
    handlers/GPXtypeTagHandler.h \
    handlers/GPXurlnameTagHandler.h \
    handlers/GPXurlTagHandler.h \
    handlers/GPXwptTagHandler.h

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

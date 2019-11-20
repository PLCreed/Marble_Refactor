### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = satellitesd
}
CONFIG(release, debug|release) {
    TARGET = satellites
}

INCLUDEPATH += $$SRC_ROOT_PATH/3rdparty/src/sgp4

### 源代码\n#######################################################################################################################
SOURCES += \
    ../../../3rdparty/src/sgp4/sgp4ext.cpp \
    ../../../3rdparty/src/sgp4/sgp4io.cpp \
    ../../../3rdparty/src/sgp4/sgp4unit.cpp \
    SatellitesConfigAbstractItem.cpp \
    SatellitesConfigDialog.cpp \
    SatellitesConfigLeafItem.cpp \
    SatellitesConfigModel.cpp \
    SatellitesConfigNodeItem.cpp \
    SatellitesModel.cpp \
    SatellitesMSCItem.cpp \
    SatellitesPlugin.cpp \
    SatellitesTLEItem.cpp \
    TrackerPluginItem.cpp \
    TrackerPluginModel.cpp

HEADERS += \
    ../../../3rdparty/src/sgp4/sgp4ext.h \
    ../../../3rdparty/src/sgp4/sgp4io.h \
    ../../../3rdparty/src/sgp4/sgp4unit.h \
    SatellitesConfigAbstractItem.h \
    SatellitesConfigDialog.h \
    SatellitesConfigLeafItem.h \
    SatellitesConfigModel.h \
    SatellitesConfigNodeItem.h \
    SatellitesModel.h \
    SatellitesMSCItem.h \
    SatellitesPlugin.h \
    SatellitesTLEItem.h \
    TrackerPluginItem.h \
    TrackerPluginModel.h

FORMS += \
    SatellitesConfigDialog.ui

RESOURCES += \
    satellites.qrc

DISTFILES += \
    ../../../3rdparty/src/sgp4/CMakeLists.txt \
    ../../../3rdparty/src/sgp4/README \
    CMakeLists.txt

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

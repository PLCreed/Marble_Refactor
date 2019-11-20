### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = GeoCluePositionProviderPlugind
}
CONFIG(release, debug|release) {
    TARGET = GeoCluePositionProviderPlugin
}

### 源代码\n#######################################################################################################################
SOURCES += \
    GeoCluePositionProviderPlugin.cpp \
    GeoCute/Accuracy.cpp \
    GeoCute/MasterClient.cpp \
    GeoCute/PositionProvider.cpp \
    GeoCute/Provider.cpp \
    GeoCute/SimpleDBusInterface.cpp \
    GeoCute/VelocityProvider.cpp

HEADERS += \
    GeoCluePositionProviderPlugin.h \
    GeoCute/Accuracy.h \
    GeoCute/AccuracyLevel.h \
    GeoCute/MasterClient.h \
    GeoCute/MasterClient_p.h \
    GeoCute/Position.h \
    GeoCute/PositionProvider.h \
    GeoCute/PositionProvider_p.h \
    GeoCute/Provider.h \
    GeoCute/Provider_p.h \
    GeoCute/SimpleDBusInterface.h \
    GeoCute/Status.h \
    GeoCute/Velocity.h \
    GeoCute/VelocityProvider.h \
    GeoCute/VelocityProvider_p.h

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

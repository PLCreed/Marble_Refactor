### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = EarthquakePlugind
}
CONFIG(release, debug|release) {
    TARGET = EarthquakePlugin
}

### 源代码\n#######################################################################################################################
SOURCES += \
    EarthquakeItem.cpp \
    EarthquakeModel.cpp \
    EarthquakePlugin.cpp

HEADERS += \
    EarthquakeItem.h \
    EarthquakeModel.h \
    EarthquakePlugin.h

FORMS += \
    EarthquakeConfigWidget.ui

RESOURCES += \
    earthquake.qrc

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

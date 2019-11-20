### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = WeatherPlugind
}
CONFIG(release, debug|release) {
    TARGET = WeatherPlugin
}

### 源代码\n#######################################################################################################################
SOURCES += \
    AbstractWeatherService.cpp \
    BBCItemGetter.cpp \
    BBCParser.cpp \
    BBCStation.cpp \
    BBCWeatherItem.cpp \
    BBCWeatherService.cpp \
    FakeWeatherItem.cpp \
    FakeWeatherService.cpp \
    GeoNamesWeatherItem.cpp \
    GeoNamesWeatherService.cpp \
    StationListParser.cpp \
    WeatherData.cpp \
    WeatherItem.cpp \
    WeatherModel.cpp \
    WeatherPlugin.cpp

HEADERS += \
    AbstractWeatherService.h \
    BBCItemGetter.h \
    BBCParser.h \
    BBCStation.h \
    BBCWeatherItem.h \
    BBCWeatherService.h \
    FakeWeatherItem.h \
    FakeWeatherService.h \
    GeoNamesWeatherItem.h \
    GeoNamesWeatherService.h \
    StationListParser.h \
    WeatherData.h \
    weatherGlobal.h \
    WeatherItem.h \
    WeatherModel.h \
    WeatherPlugin.h \
    data/weather.html

FORMS += \
    WeatherConfigWidget.ui

RESOURCES += \
    weather.qrc

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

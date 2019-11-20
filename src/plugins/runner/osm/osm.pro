### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = osmd
}
CONFIG(release, debug|release) {
    TARGET = osm
}

INCLUDEPATH += $$PWD/writers \
               $$PWD/translators \
               $$SRC_ROOT_PATH/3rdparty/src/o5mreader


### 源代码\n#######################################################################################################################
SOURCES += \
    ../../../3rdparty/src/o5mreader/o5mreader.cpp \
    OsmElementDictionary.cpp \
    OsmNode.cpp \
    OsmParser.cpp \
    OsmPlugin.cpp \
    OsmRelation.cpp \
    OsmRunner.cpp \
    OsmWay.cpp \
    translators/O5mWriter.cpp \
    translators/OsmConverter.cpp \
    translators/OsmDocumentTagTranslator.cpp \
    writers/OsmNodeTagWriter.cpp \
    writers/OsmObjectAttributeWriter.cpp \
    writers/OsmRelationTagWriter.cpp \
    writers/OsmTagTagWriter.cpp \
    writers/OsmTagWriter.cpp \
    writers/OsmWayTagWriter.cpp

HEADERS += \
    ../../../3rdparty/src/o5mreader/o5mreader.h \
    OsmElementDictionary.h \
    OsmNode.h \
    OsmParser.h \
    OsmPlugin.h \
    OsmRelation.h \
    OsmRunner.h \
    OsmWay.h \
    translators/O5mWriter.h \
    translators/OsmConverter.h \
    translators/OsmDocumentTagTranslator.h \
    writers/OsmNodeTagWriter.h \
    writers/OsmObjectAttributeWriter.h \
    writers/OsmRelationTagWriter.h \
    writers/OsmTagTagWriter.h \
    writers/OsmTagWriter.h \
    writers/OsmWayTagWriter.h

DISTFILES += \
    ../../../3rdparty/src/o5mreader/CMakeLists.txt \
    ../../../3rdparty/src/o5mreader/LICENSE

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

### 项目配置
#######################################################################################################################
include ($$SRC_ROOT_PATH/core/marble_core.pri)

TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(debug, debug|release) {
    TARGET = annotated
}
CONFIG(release, debug|release) {
    TARGET = annotate
}

### 源代码\n#######################################################################################################################
SOURCES += \
    AnnotatePlugin.cpp \
    AreaAnnotation.cpp \
    DownloadOsmDialog.cpp \
    EditGroundOverlayDialog.cpp \
    EditPolygonDialog.cpp \
    EditPolylineDialog.cpp \
    GroundOverlayFrame.cpp \
    MergingPolygonNodesAnimation.cpp \
    MergingPolylineNodesAnimation.cpp \
    NodeItemDelegate.cpp \
    NodeModel.cpp \
    PlacemarkTextAnnotation.cpp \
    PolylineAnnotation.cpp \
    PolylineNode.cpp \
    SceneGraphicsItem.cpp \
    SceneGraphicsTypes.cpp

HEADERS += \
    AnnotatePlugin.h \
    AreaAnnotation.h \
    DownloadOsmDialog.h \
    EditGroundOverlayDialog.h \
    EditPolygonDialog.h \
    EditPolylineDialog.h \
    GroundOverlayFrame.h \
    MergingPolygonNodesAnimation.h \
    MergingPolylineNodesAnimation.h \
    NodeItemDelegate.h \
    NodeModel.h \
    PlacemarkTextAnnotation.h \
    PolylineAnnotation.h \
    PolylineNode.h \
    SceneGraphicsItem.h \
    SceneGraphicsTypes.h

FORMS += \
    DownloadOsmDialog.ui \
    EditGroundOverlayDialog.ui \
    EditPolygonDialog.ui \
    EditPolylineDialog.ui

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

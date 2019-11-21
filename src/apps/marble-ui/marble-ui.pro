include ($$SRC_ROOT_PATH/core/marble_core.pri)

QT += gui

CONFIG += c++11

CONFIG(debug, debug|release) {
    TARGET = MarbleQtd
}
CONFIG(release, debug|release) {
    TARGET = MarbleQt
}

DESTDIR = $$DEBUG_DESDIR

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    ControlView.h \
    mainwindow.h

SOURCES += \
        ControlView.cpp \
        main.cpp \
        mainwindow.cpp

########################################################################################################################
#target.path += $$DEBUG_DESDIR/

## Debug
#interactive_libs_debug.files += $$OUT_PWD/debug/*.exe
#interactive_libs_debug.path += $$DEBUG_DESDIR/
## Release
#interactive_libs_release.files += $$OUT_PWD/release/*.exe
#interactive_libs_release.path += $$DEBUG_DESDIR/

#CONFIG(debug, debug|release) {
#    INSTALLS += interactive_libs_debug
#}
#CONFIG(release, debug|release) {
#    INSTALLS += interactive_libs_release
#}

RESOURCES += \
    marble.qrc

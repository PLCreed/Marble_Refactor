INCLUDEPATH += $$PWD/include

CONFIG(debug, debug|release) {
    # zlib
    LIBS += -L$$PWD/lib/ -lzlib
}

CONFIG(release, debug|release) {
    # zlib
    LIBS += -L$$PWD/lib/ -lzlibd
}

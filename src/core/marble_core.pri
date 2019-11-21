QT += gui widgets quick concurrent network xml svg webenginewidgets dbus

INCLUDEPATH += $$PWD \
               $$PWD/astro \
               $$PWD/marble \
               $$PWD/marble/blendings \
               $$PWD/marble/cloudsync \
               $$PWD/marble/declarative \
               $$PWD/marble/geodata \
               $$PWD/marble/geodata\data \
               $$PWD/marble/geodata\graphicsitem \
               $$PWD/marble/geodata\handlers\dgml \
               $$PWD/marble/geodata\handlers\kml \
               $$PWD/marble/geodata\parser \
               $$PWD/marble/geodata\scene \
               $$PWD/marble/geodata\writer \
               $$PWD/marble/geodata\writers\dgml \
               $$PWD/marble/geodata\writers\kml \
               $$PWD/marble/graphicsview \
               $$PWD/marble/layers \
               $$PWD/marble/osm \
               $$PWD/marble/projections \
               $$PWD/marble/routing \
               $$PWD/marble/routing/instructions \
               $$BUILD_ROOT_PATH/core/marble

win32:CONFIG(release, debug|release) {
    LIBS += -L$$BUILD_ROOT_PATH/core/astro/release/ -lastro
    LIBS += -L$$BUILD_ROOT_PATH/core/marble/release/ -lmarble
}
else:win32:CONFIG(debug, debug|release) {
    LIBS += -L$$BUILD_ROOT_PATH/core/astro/debug/ -lastrod
    LIBS += -L$$BUILD_ROOT_PATH/core/marble/debug/ -lmarbled
}
else:unix:!macx: LIBS += -L$$BUILD_ROOT_PATH/core/astro/ -lastro \
                 LIBS += -L$$BUILD_ROOT_PATH/core/marble/ -lmarble

INCLUDEPATH += $$PWD \
               $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$BUILD_ROOT_PATH/core/astro/release/ -lastro
else:win32:CONFIG(debug, debug|release): LIBS += -L$$BUILD_ROOT_PATH/core/astro/debug/ -lastrod
else:unix:!macx: LIBS += -L$$BUILD_ROOT_PATH/core/astro/ -lastro

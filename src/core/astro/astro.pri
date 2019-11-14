INCLUDEPATH += $$PWD \
               $$PWD/../

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../astro/release/ -lastro
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../astro/debug/ -lastrod
else:unix:!macx: LIBS += -L$$OUT_PWD/../astro/ -lastro

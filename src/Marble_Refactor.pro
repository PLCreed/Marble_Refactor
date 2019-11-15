TEMPLATE = subdirs
CONFIG   += ordered

SUBDIRS += 3rdparty \
           core \
           plugins \
           apps

OTHER_FILES += .clang-format \
               .qmake.conf

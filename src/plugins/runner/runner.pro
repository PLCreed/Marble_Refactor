TEMPLATE = subdirs
CONFIG   += ordered

SUBDIRS += cache \
           cyclestreets \
           geouri \
           gosmore-reversegeocoding \
           gosmore-routing \
           gpsbabel \
           gpx \
           hostip \
           json \
           kml \
           latlon \
           local-osm-search \
           localdatabase \
           log \
           mapquest \
           monav \
           nominatim-reversegeocoding \
           nominatim-search \
           open-source-routing-machine \
           openlocation-code-search \
           openrouteservice \
           osm \
           pn2 \
           pnt \
           routino \
           shp \
#           traveling-salesman \
           yours

DISTFILES += \
    CMakeLists.txt

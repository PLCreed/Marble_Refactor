TEMPLATE = subdirs
CONFIG   += ordered

SUBDIRS += annotate \
#           aprs \
           atmosphere \
           compass \
           crosshairs \
           earthquake \
           eclipses \
           elevationprofilefloatitem \
           elevationprofilemarker \
#           fileview \
           foursquare \
           gpsinfo \
           graticule \
           license \
           mapscale \
           measure \
           navigation \
           notes \
#           opencaching \
           opendesktop \
           overviewmap \
#           panoramio \
           photo \
           positionmarker \
           postalcode \
           progress \
           routing \
           satellites \
           speedometer \
           stars \
           sun \
           test \
#           twitter \
           weather \
           wikipedia

DISTFILES += \
    CMakeLists.txt

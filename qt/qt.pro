TEMPLATE = app

QT += qml quick location

SOURCES += main.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

MEMPHIS_ROOT=$$clean_path($${_PRO_FILE_PWD_}/..)
DEFINES += MEMPHIS_ROOT=\"\\\"$${MEMPHIS_ROOT}\\\"\"

import QtQuick 2.4
import QtQuick.Window 2.2
import QtLocation 5.5

Window {
    width: 640
    height: 480
    visible: true
    Map {
        center {
            latitude: 47.141
            longitude: 9.521
        }
        zoomLevel: 15

        anchors.fill: parent
        activeMapType: supportedMapTypes[7] // FIXME: Remove dirty hard-coded index
        plugin: Plugin {
            name: "osm"
            PluginParameter { name: "osm.mapping.host"; value: "http://localhost:8080/" }
        }
    }
}

import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6
Rectangle{
    property double oldLat: 25.658
    property double oldLng: 100.3658
    Plugin{
        id: mapPlugin
        name : "osm"

    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin:  mapPlugin
        center :QtPositioning.coordinate(25.6585,oldLng);
        zoomLevel: 15
    }
function setCenter(lat,lng)
{
  mapView.pan(oldLat - Lat,oldLng -lng)
    oldLat = lat
    oldLng = lng
}
}


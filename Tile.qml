import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

Rectangle {
    id: root

    property string displayText: ""
    //property alias internalText: _firstText
    //readonly property alias internalText: _firstText

    color: "forestgreen"
    border {
        color: "black"
        width: 0.5
    }
    radius: 3

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        boundingRadius: root.height - 50

        image.source: "qrc:/qml/resources/" + root.displayText + ".svg"
    }

    Text {
        id: _firstText
        /*
        x: root.width / 2 - width / 2
        y: root.height / 2 - height / 2*/
        //anchors.horizontalCenter: root.horizontalCenter
        //anchors.verticalCenter: root.verticalCenter

        //anchors.centerIn: root
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right //root.left
        anchors.leftMargin: 5 //Style.defaultOffset

        //text: index
        text: root.displayText//"1"

        /*
        font.pointSize: 24
        font.bold: true*/
        font {
            pointSize: Math.min(root.width, root.height) / 8 //24
            bold: true
        }
    }

    Text {
        id: _secondText
        //anchors.left: _firstText.right
        //anchors.leftMargin: 3
        //anchors.verticalCenter: _firstText.verticalCenter

        anchors.left: _contactBubble.right
        anchors.leftMargin: 2
        anchors.top:  _firstText.bottom
        text: "container"

        font {
            pointSize: Math.min(root.width, root.height) / 18
            bold: false
            italic: true
        }
    }

}

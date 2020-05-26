import QtQuick 2.12
import QtQuick.Window 2.12
import StyleSettings 1.0
import ContactsModule.Impl 1.0

Window {
    id: root
    visible: true
    width: 1280
    height: 800
    title: qsTr("ListView test application with singletone & dir architekture")
    color: Style.backgroundColor
    opacity: Style.emphasisOpacity

    Board {
        //anchors.fill: parent
        anchors.left: parent
        width: parent.width / 4
        height: parent.height
    }

    ListBoard {

        anchors.right: parent
        x: parent.width - parent.width / 3
        width: parent.width / 3
        height: parent.height

        ContactsView {
            anchors.fill: parent
        }

        Rectangle {
            id: _background
            z: -100
            anchors.fill: parent
            color: Style.backgroundColor
            opacity: Style.emphasisOpacity
        }
    }
}

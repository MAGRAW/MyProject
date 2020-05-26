import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        boundingRadius: root.height - 15

        image.source: Resources.contacts.defaultContactIcon
    }

    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right //root.left
        anchors.leftMargin: Style.defaultOffset

        Row {
            spacing: Style.smallSpacing
            BaseText {
                text: name + ":"
            }
            BaseText {
                text: surname
            }
        }
        BaseText {
            text: "cmd: " + phoneNumber
           color: Style.primaryColor
        }
    }
}

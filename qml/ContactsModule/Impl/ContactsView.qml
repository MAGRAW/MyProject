import QtQuick 2.0
import Contacts 1.0
import ContactsModule.Base 1.0

BaseListView {
    id: root
    /*model: ListModel {
        ListElement  {
            name: "Script1"
            surname: "Teeeesting1"
            phoneNumber: "00101000111000001100010101"
        }
        ListElement  {
            name: "Script2"
            surname: "Teeeesting2"
            phoneNumber: "10100101010010101010000010"
        }
        ListElement  {
            name: "Script3"
            surname: "Teeeesting3"
            phoneNumber: "01010010101000100010001000"
        }
    }*/
    model: ContactsModel {
    }

    delegate: ContactDelegate {
        width: root.width
        height: 100
    }
}

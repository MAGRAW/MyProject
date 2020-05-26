import QtQuick 2.0
import GUIexample 1.0;

GridView {
    id: root
    //model: 16
    model: BoardModel {
    }

    cellHeight: height / root.model.dimension //4
    cellWidth: width / root.model.dimension //4

    delegate: Item {
        id: _backgroundDelegate
        width: root.cellWidth
        height: root.cellHeight

        visible: display !== root.model.hiddenElementValue //16 //"эл16" // !== "эл16"

        Tile {
            /*
            //displayText: index//индекс делегата в модели
            displayText: display//"1"
            //internalText.text: display
            //width: root.width / 4 //100
            //height: root.height / 4 //100
            width: root.cellWidth
            height: root.cellHeight
            */
            anchors.fill: _backgroundDelegate
            anchors.margins: 1
            displayText: display
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.model.move(index);
                }
            }
        }
    }
}

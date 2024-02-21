import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    width: 600
    height: 800

    GridLayout {
        id: buttons_grid
        columns: 5

        anchors.fill: parent

        component TextButton : Button {
            width: 100
            height: 50
        }

        TextButton {
            id: button_0
        }
        TextButton {
            id: button_1
        }
        TextButton {
            id: button_2
        }
        TextButton {
            id: button_3
        }
        TextButton {
            id: button__4
        }
        TextButton {
            id: button__5
        }
    }
}
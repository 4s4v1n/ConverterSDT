import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {

    GridLayout {
        id: buttons_grid_layout
        columns: 4
        rows: 5
        rowSpacing: 20
        columnSpacing: 10
        anchors.fill: parent

        component TextButton : Button {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: parent.width / parent.columns
            Layout.preferredHeight: parent.height / parent.rows
        }

        TextButton {
            id: button_0
            text: "0"
        }

        TextButton {
            id: button_1
            text: "1"
        }

        TextButton {
            id: button_2
            text: "2"
        }

        TextButton {
            id: button_3
            text: "3"
        }

        TextButton {
            id: button_4
            text: "4"
        }

        TextButton {
            id: button_5
            text: "5"
        }

        TextButton {
            id: button_6
            text: "6"
        }

        TextButton {
            id: button_7
            text: "7"
        }

        TextButton {
            id: button_8
            text: "8"
        }

        TextButton {
            id: button_9
            text: "9"
        }

        TextButton {
            id: button_a
            text: "A"
        }

        TextButton {
            id: button_b
            text: "B"
        }

        TextButton {
            id: button_c
            text: "C"
        }

        TextButton {
            id: button_d
            text: "D"
        }

        TextButton {
            id: button_e
            text: "E"
        }

        TextButton {
            id: button_f
            text: "F"
        }

        TextButton {
            id: button_dot
            text: "."
        }

        TextButton {
            id: button_ac
            text: "AC"
        }

        TextButton {
            id: button_ce
            text: "CE"
        }

        TextButton {
            id: button_convert
            text: "CONVERT"
        }
    }
}
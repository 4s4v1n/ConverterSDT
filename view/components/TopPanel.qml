import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    component NumberControlPanel : Rectangle {
        property alias valueLabelText: value_label.text
        property alias baseLabelText: base_label.text

        GridLayout {
            id: grid_layout
            columns: 2
            rows: 2
            rowSpacing: 20
            columnSpacing: 10
            anchors.fill: parent

            Text {
                id: value_label

                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height / parent.rows
            }

            TextInput {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height / parent.rows
            }

            Text {
                id: base_label

                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height / parent.rows
            }

            SpinBox {
                from: 2
                to: 16
                value: 2

                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height / parent.rows
            }
        }
    }

    NumberControlPanel {
        id: input_panel

        height: parent.height / 2
        valueLabelText: qsTr("Переводимое число")
        baseLabelText: qsTr("Основание переводимого числа")

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
    }

    NumberControlPanel {
        id: output_panel

        height: parent.height / 2
        valueLabelText: qsTr("Переводённое число")
        baseLabelText: qsTr("Основание переведённого числа")

        anchors {
            top: input_panel.bottom
            left: parent.left
            right: parent.right
        }
    }
}
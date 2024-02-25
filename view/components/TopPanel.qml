import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property alias inputValue: input_panel.value
    property alias outputValue: output_panel.value
    property alias inputBase: input_panel.baseSpinbox.value

    signal outputBaseValueChanged()

    component BaseText : Text {
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignHCenter

        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.preferredWidth: parent.width / parent.columns
        Layout.preferredHeight: parent.height / parent.rows
    }

    component NumberControlPanel : Rectangle {
        property alias valueLabelText: value_label.text
        property alias baseLabelText: base_label.text
        property alias baseSpinbox: spinbox
        property alias value: number_line.text


        GridLayout {
            id: grid_layout
            columns: 2
            rows: 2
            rowSpacing: 20
            columnSpacing: 10
            anchors.fill: parent

            BaseText {
                id: value_label
            }

            BaseText {
                id: number_line
            }

            BaseText {
                id: base_label
            }

            SpinBox {
                id: spinbox
                from: 2
                to: 16
                value: 2

                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.preferredWidth: parent.width / parent.columns
                Layout.preferredHeight: parent.height / parent.rows

                onValueChanged: {
                    slider.value = value
                }
            }

            Slider {
                id: slider
                from: 2
                to: 16
                stepSize: 1
                snapMode: Slider.SnapAlways

                Layout.fillHeight: true
                Layout.fillWidth: true

                onValueChanged: {
                    spinbox.value = value
                }
            }
        }
    }

    NumberControlPanel {
        id: input_panel
        height: parent.height / 2
        valueLabelText: qsTr("Переводимое число")
        baseLabelText: qsTr("Основание переводимого числа")

        baseSpinbox {
            onValueChanged: {
                Controller.setInputBase(baseSpinbox.value)
            }
            Component.onCompleted: {
                Controller.setInputBase(baseSpinbox.value)
            }
        }

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

        baseSpinbox {
            onValueChanged: {
                Controller.setOutputBase(baseSpinbox.value)
                outputBaseValueChanged()
            }
            Component.onCompleted: {
                Controller.setOutputBase(baseSpinbox.value)
            }
        }

        anchors {
            top: input_panel.bottom
            left: parent.left
            right: parent.right
        }
    }
}

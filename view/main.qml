import QtQuick
import QtQuick.Controls

import "components"

Window {
    id: window
    width: 600
    height: 800
    flags: Qt.Window
    visible: true

    BottomPanel {
        height: parent.height / 2

        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            leftMargin: 10
            rightMargin: 10
            bottomMargin: 10
        }
    }
}
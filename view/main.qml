import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "components"

Window {
    id: window
    width: 600
    height: 800
    flags: Qt.Window
    visible: true

    TopPanel {
        id: top_panel
        height: parent.height / 2

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
    }

    BottomPanel {
        id: bottom_panel
        height: parent.height / 2

        anchors {
            top: top_panel.bottom
            left: parent.left
            right: parent.right
        }
    }
}

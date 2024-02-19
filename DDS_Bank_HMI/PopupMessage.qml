import QtQuick 2.12
import QtQuick.Controls 2.15

Popup
{
    id: popup
    anchors.centerIn: parent
    width: parent.width/2
    height: parent.height/2
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    Text
    {
        id: textPopup
        width: parent.width - 5
        height: parent.height - 5
        anchors.centerIn: parent
        wrapMode: Text.WrapAnywhere
        text: qsTr("Hola buenaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaas tardes")
    }
}

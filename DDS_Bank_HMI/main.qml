import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Window {
    id: appWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout
    {
        RowLayout
        {
            id: mainRL
            RadioButton
            {
                id: depositRB
                text: "Deposit"

                onClicked:
                {
                    deposit.visible = true;
                    withdraw.visible = false;
                }
            }
            RadioButton
            {
                id: withdrawRB
                text: "Withdraw"

                onClicked:
                {
                    deposit.visible = false;
                    withdraw.visible = true;
                }
            }
            RadioButton
            {
                id: transferRB
                text: "Transfer"

                onClicked:
                {
                    deposit.visible = false;
                }
            }
        }


        Deposit
        {
            id: deposit
            visible: false
        }

        Withdraw
        {
            id: withdraw
            visible: false
        }
    }


}

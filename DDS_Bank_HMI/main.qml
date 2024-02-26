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
        SelectLanguage
        {
            id: selectLanguage
            visible: true
        }

        RowLayout
        {
            id: mainRL
            RadioButton
            {
                id: depositRB
                objectName: "depositRB"
                text: depositText

                onClicked:
                {
                    deposit.visible = true;
                    withdraw.visible = false;
                    transfer.visible = false;
                }
            }
            RadioButton
            {
                id: withdrawRB
                objectName: "withdrawRB"
                text: withdrawText

                onClicked:
                {
                    deposit.visible = false;
                    withdraw.visible = true;
                    transfer.visible = false;
                }
            }
            RadioButton
            {
                id: transferRB
                objectName: "transferRB"
                text: transferText

                onClicked:
                {
                    deposit.visible = false;
                    withdraw.visible = false;
                    transfer.visible = true;
                }
            }
        }

        SelectFund
        {
            id: selectFund
            visible: true
        }

        Visualize
        {
            id: visualize
            visible: true
        }

        Deposit
        {
            id: deposit
            objectName: "deposit"
            visible: false
        }

        Withdraw
        {
            id: withdraw
            objectName: "withdraw"
            visible: false
        }

        Transfer
        {
            id: transfer
            objectName: "transfer"
            visible: false
        }
    }

    PopupMessage
    {
        id: popupMessage
        objectName: "popupMessage"
    }
}

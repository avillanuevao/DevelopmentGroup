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

    // vector A

    ListModel
    {
        id: allFundsModel
        // ListElement{text: a[0]}
        ListElement { text: "Savings" }
        ListElement { text: "Housing" }
    }

    // si quiero cambiar el orden, cambio primero el vector a (estará en c++) y luego cambio el orden del ListElement


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
                    transfer.visible = false;
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
                    transfer.visible = false;
                }
            }
            RadioButton
            {
                id: transferRB
                text: "Transfer"

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
            fundsModel: allFundsModel
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
            visible: false
        }

        Withdraw
        {
            id: withdraw
            visible: false
        }

        Transfer
        {
            id: transfer
            fundsModel: allFundsModel
            visible: false
        }
    }

    PopupMessage
    {
        id: popupMessage
        objectName: "popupMessage"
    }


}

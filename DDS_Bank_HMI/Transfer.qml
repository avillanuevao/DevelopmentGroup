import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutTransfer

    property alias fundsModel: fundTypeDestinationTransferComboBox.model

    RowLayout
    {
        Text
        {
            id: destinationTransfer
            text: qsTr("Destination Transfer: ")
        }

        ComboBox
        {
            id: fundTypeDestinationTransferComboBox

            onCurrentIndexChanged:
            {
                transferMoneyView.setDestinationFundType(fundTypeDestinationTransferComboBox.currentIndex);
            }
        }
    }

    TextField
    {
        id: amountTransferTextField
        placeholderText: "Amount transfer"
        validator: RegExpValidator{ regExp: /^\d+$/ }
    }

    Button
    {
        id: acceptTransferButton
        text: "Accept"

        onClicked:
        {
            transferMoneyView.setAmountToTransfer(amountTransferTextField.text)
            transferMoneyView.transferMoney();
        }
    }
}

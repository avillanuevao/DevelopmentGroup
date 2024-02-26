import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutTransfer
    property alias textButton: acceptButton.text
    property alias textDestination: destinationTransfer.text
    property alias placeholderText: amountTextField.placeholderText
    property alias modelFund: fundTypeDestinationTransferComboBox.model

    RowLayout
    {
        Text
        {
            id: destinationTransfer
            text: destinationTransferText
        }

        ComboBox
        {
            id: fundTypeDestinationTransferComboBox
            model: fundsAvailables
            onCurrentTextChanged:
            {
                transferMoneyView.setDestinationFundType(fundTypeDestinationTransferComboBox.currentText);
            }
        }
    }

    TextField
    {
        id: amountTextField
        placeholderText: amountTransfer
        validator: RegExpValidator{ regExp: /^\d+$/ }
    }

    Button
    {
        id: acceptButton
        text: accept

        onClicked:
        {
            transferMoneyView.setAmountToTransfer(amountTransferTextField.text)
            transferMoneyView.transferMoney();
        }
    }
}

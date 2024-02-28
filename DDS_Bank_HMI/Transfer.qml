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
        }

        ComboBox
        {
            id: fundTypeDestinationTransferComboBox
            onCurrentTextChanged:
            {
                transferMoneyView.setDestinationFundType(fundTypeDestinationTransferComboBox.currentText);
            }
        }
    }

    TextField
    {
        id: amountTextField
        validator: RegExpValidator{ regExp: /^\d+$/ }
    }

    Button
    {
        id: acceptButton

        onClicked:
        {
            transferMoneyView.setAmountToTransfer(amountTextField.text)
            transferMoneyView.transferMoney();
        }
    }
}

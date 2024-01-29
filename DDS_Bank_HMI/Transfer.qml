import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutTransfer

    RowLayout
    {
        ComboBox
        {
            id: fundTypeOriginTransferComboBox
            model: ListModel
            {
                ListElement {text: "Savings"}
                ListElement {text: "Housing"}
            }

            onCurrentIndexChanged:
            {
                transferMoneyView.setOriginFundType(fundTypeOriginTransferComboBox.currentIndex);
                //            depositMoneyView.setFundType(fundTypeCB.currentIndex)
                //            console.log("Indice seleccionado: ", fundTypeCB.currentIndex);
                //            displayT.text = depositMoneyView.getAmountFromFund()
            }
        }

        ComboBox
        {
            id: fundTypeDestinyTransferComboBox
            model: ListModel
            {
                ListElement {text: "Savings"}
                ListElement {text: "Housing"}
            }

            onCurrentIndexChanged:
            {
                transferMoneyView.setDestinationFundType(fundTypeDestinyTransferComboBox.currentIndex);
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

    Text {
        objectName: "displayTransferText"
        id: displayTransferText
        text: transferMoneyView.getAmountFromOriginFund();
    }
}

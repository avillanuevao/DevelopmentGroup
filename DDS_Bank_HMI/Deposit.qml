import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout

    TextField
    {
        id: amount
        placeholderText: "Amount deposit"

        validator: RegExpValidator{ regExp: /^\d+$/ }
        onTextChanged:
        {

            console.log(amount.text)
        }
    }

    Button
    {
        id: acceptB
        text: "Accept"

        onClicked:
        {
            depositMoneyView.setAmountToDeposit(amount.text)
            depositMoneyView.depositMoney()
        }
    }

    ComboBox
    {
        id: visualizeFundTypeComboBox
        model: ListModel
        {
            ListElement {text: "Savings"}
            ListElement {text: "Housing"}
        }

        onCurrentIndexChanged:
        {
            depositMoneyView.setFundType(fundTypeCB.currentIndex)
            console.log("Indice seleccionado: ", fundTypeCB.currentIndex);
            displayT.text = depositMoneyView.getAmountFromFund()
        }
    }

    Text
    {
        id: visualizeAmount
        objectName: "displayT"
        text: depositMoneyView.getAmountFromFund()
    }
}

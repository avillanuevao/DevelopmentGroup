import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutW

    ComboBox
    {
        id: fundTypeCBW
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

    TextField
    {
        id: amountW
        placeholderText: "Amount withdraw"

        validator: RegExpValidator{ regExp: /^\d+$/ }
        onTextChanged:
        {

            console.log(amount.text)
        }
    }

    Button
    {
        id: acceptBW
        text: "Accept"

        onClicked:
        {
            depositMoneyView.setAmountToDeposit(amount.text)
            depositMoneyView.depositMoney()
        }
    }

    Text {
        objectName: "displayT"
        id: displayTW
        text: depositMoneyView.getAmountFromFund()
    }
}

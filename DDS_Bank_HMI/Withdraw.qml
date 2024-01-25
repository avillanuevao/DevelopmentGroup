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
            withdrawMoneyView.setFundType(fundTypeCBW.currentIndex)
            console.log("Indice seleccionado: ", fundTypeCBW.currentIndex);
            displayTW.text = withdrawMoneyView.getAmountFromFund()
        }
    }

    TextField
    {
        id: amountW
        placeholderText: "Amount withdraw"

        validator: RegExpValidator{ regExp: /^\d+$/ }
        onTextChanged:
        {

            console.log(amountW.text)
        }
    }

    Button
    {
        id: acceptBW
        text: "Accept"

        onClicked:
        {
            withdrawMoneyView.setAmountToWithdraw(amountW.text)
            withdrawMoneyView.withdrawMoney()
        }
    }

    Text {
        id: displayTW
        objectName: "displayTW"
        text: withdrawMoneyView.getAmountFromFund()
    }
}

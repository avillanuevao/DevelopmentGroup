import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutWithdraw

    TextField
    {
        id: amountWithdraw
        placeholderText: "Amount withdraw"

        validator: RegExpValidator{ regExp: /^\d+$/ }
        onTextChanged:
        {

            console.log(amountWithdraw.text)
        }
    }

    Button
    {
        id: acceptBW
        text: "Accept"

        onClicked:
        {
            withdrawMoneyView.setAmountToWithdraw(amountWithdraw.text)
            withdrawMoneyView.withdrawMoney()
        }
    }
}

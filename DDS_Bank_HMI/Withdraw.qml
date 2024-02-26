import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayoutWithdraw
    property alias textButton: acceptButton.text
    property alias placeholderText: amountTextField.placeholderText

    TextField
    {
        id: amountTextField
        placeholderText: amountWithdraw

        validator: RegExpValidator{ regExp: /^\d+$/ }
        onTextChanged:
        {

            console.log(amountWithdraw.text)
        }
    }

    Button
    {
        id: acceptButton
        text: accept

        onClicked:
        {
            withdrawMoneyView.setAmountToWithdraw(amountWithdraw.text)
            withdrawMoneyView.withdrawMoney()
        }
    }
}

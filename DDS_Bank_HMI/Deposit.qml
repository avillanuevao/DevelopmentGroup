import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ColumnLayout
{
    id: columnLayout
    property alias textButton: acceptButton.text
    property alias placeholderText: amountTextField.placeholderText

    TextField
    {
        id: amountTextField
        placeholderText: amountDeposit

        validator: RegExpValidator{ regExp: /^\d+$/ }
    }

    Button
    {
        id: acceptButton
        text: accept

        onClicked:
        {
            depositMoneyView.setAmountToDeposit(amount.text)
            depositMoneyView.depositMoney()
        }
    }
}

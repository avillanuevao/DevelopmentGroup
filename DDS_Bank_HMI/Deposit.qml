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
}

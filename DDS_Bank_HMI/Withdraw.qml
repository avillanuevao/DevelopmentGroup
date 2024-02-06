import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
//TO
ColumnLayout
{
//    id: columnLayoutW

    TextField
    {
        id: amountW
        placeholderText: "Amount withdraw"

//        validator: RegExpValidator{ regExp: /^\d+$/ }
//        onTextChanged:
//        {

//            console.log(amountW.text)
//        }
//    }

//    Button
//    {
//        id: acceptBW
//        text: "Accept"

        onClicked:
        {
            withdrawMoneyView.setAmountToWithdraw(amountW.text)
            withdrawMoneyView.withdrawMoney()
        }
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout
    {
        id: columnLayout

        RadioButton
        {
            id: depositRB
            text: "Deposit"
        }

        ComboBox
        {
            id: fundTypeCB
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

        Text {
            objectName: "displayT"
            id: displayT
            text: depositMoneyView.getAmountFromFund()
        }
    }

}

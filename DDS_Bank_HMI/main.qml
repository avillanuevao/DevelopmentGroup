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
                depositViewMoney.setFundType(fundTypeCB.currentIndex)
                console.log("Indice seleccionado: ", fundTypeCB.currentIndex);
            }
        }

        TextField
        {
            id: amount
            placeholderText: "Amount osit"

            validator: RegExpValidator{regExp: /^-?\d+$/}
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
                depositViewMoney.setAmountToDeposit(amount.text)
                depositViewMoney.depositMoney()
            }
        }

        Text {
            objectName: "displayT"
            id: displayT
            text: depositViewMoney.getAmountFromFund()
        }
    }

}

import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


ColumnLayout
{
    id: visualizeColumnLayout
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
            //                depositMoneyView.setFundType(fundTypeCB.currentIndex)
            //                console.log("Indice seleccionado: ", fundTypeCB.currentIndex);
            //                displayT.text = depositMoneyView.getAmountFromFund()
        }
    }

    Text
    {
        id: visualizeAmount
        objectName: "displayT"
        text: "Hola"
        //text: depositMoneyView.getAmountFromFund()
    }
}



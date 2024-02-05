import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


ComboBox
{
    id: selectFundTypeComboBox
    model: ListModel
    {
        ListElement {text: "Savings"}
        ListElement {text: "Housing"}
    }

    onCurrentIndexChanged:
    {
        selectFundView.setFundType(selectFundTypeComboBox.currentIndex);
    }
}


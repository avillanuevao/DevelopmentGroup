import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


ComboBox
{
    id: selectFundTypeComboBox
    property alias modelFund: selectFundTypeComboBox.model

    onCurrentIndexChanged:
    {
        selectFundView.setFundType(selectFundTypeComboBox.currentIndex);
    }
}


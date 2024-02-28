import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12

ComboBox
{
    id: selectLanguageComboBox
    property alias modelLanguage: selectLanguageComboBox.model
    onCurrentIndexChanged:
    {
        selectLanguageView.setLanguage(selectLanguageComboBox.currentIndex)

        console.log("Indice cambiado a :" + currentIndex)
    }
}

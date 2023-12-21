import QtQuick 2.1
import QtQuick.Controls 1.1
import QtWebEngine 1.7


ApplicationWindow {

    visibility: ApplicationWindow.FullScreen
    visible: true


    WebEngineView {
        id: webview
        anchors.fill: parent
       // url: "http://192.168.5.221/map"
        url: "http://192.168.1.113:8000/map/m/"
        antialiasing: true  // Включение сглаживания может улучшить отображение


        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.BlankCursor // Скрываем курсор мыши
        }





//        Component.onCompleted: {
            // Включаем кэширование
//            webview.settings.localStorageEnabled = true;
//            webview.settings.offlineStorageDefaultQuota = 5 * 1280 * 1024; // 5 MB

            // Включает использование кэша для оффлайн-ресурсов веб-приложения
//            webview.settings.offlineWebApplicationCacheEnabled = true;

            // Позволяет использовать графику с декодированием на GPU
//            webview.settings.accelerated2dCanvasEnabled = false;
//        }


    }

}

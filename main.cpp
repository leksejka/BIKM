#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>
#include <QWebEngineSettings>
#include "toucheventfilter.h"




int main(int argc, char *argv[])
{
//    QApplication::setAttribute(Qt::AA_UseOpenGLES); //производительность выше чем OpenGL
//     QApplication::setAttribute(Qt::AA_DisableShaderDiskCache);
//     QApplication::setAttribute(Qt::AA_ImmediateWidgetCreation); //виджеты должны создаваться немедлено
//     QApplication::setAttribute(Qt::AA_NativeWindows);
//     QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps); //Указывает на использование пиксмапов с высоким разрешением для улучшения отображения на устройствах с высоким DPI.
//     QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); //Включает поддержку высокого DPI для автоматического масштабирования приложения под высокое разрешение экрана.
//     QApplication::setAttribute(Qt::AA_SynthesizeTouchForUnhandledMouseEvents, true);
//     QApplication::setAttribute(Qt::AA_SynthesizeMouseForUnhandledTouchEvents, true);

    QApplication a(argc, argv);
    QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));


//    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled, true);

    QQmlApplicationEngine engine;


   TouchEventFilter touchEventFilter;
    a.installEventFilter(&touchEventFilter);


    engine.load(QUrl(QStringLiteral("qrc:/qml_my.qml")));

    return a.exec();
}




//#include <QDesktopWidget>
//#include <QApplication>
//#include <QWebEngineView>
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QCursor>
//#include <QEnterEvent>

//class CustomView : public QGraphicsView {
//public:
//    CustomView(QWidget* parent = nullptr) : QGraphicsView(parent) {}

//protected:
//    void enterEvent(QEvent* event) override {
//        Q_UNUSED(event);

//        // Устанавливаем пустой курсор
//        qApp->setOverrideCursor(Qt::BlankCursor);
//    }
//};

//int main(int argc, char* argv[]) {
//    QApplication::setAttribute(Qt::AA_UseOpenGLES);
//    QApplication a(argc, argv);
//    QRect screenGeometry = QApplication::desktop()->screenGeometry();

//    CustomView view;
//    view.setGeometry(screenGeometry);

//    QWebEngineView mapViewWidget;
//    mapViewWidget.setUrl(QUrl("http://192.168.5.221/map"));
//    mapViewWidget.resize(screenGeometry.width(), screenGeometry.height());

//    QGraphicsScene scene;
//    scene.addWidget(&mapViewWidget);
//    view.setScene(&scene);
//    view.showFullScreen();

//    return a.exec();
//}

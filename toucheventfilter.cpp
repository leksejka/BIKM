#include "toucheventfilter.h"
#include <QApplication>

TouchEventFilter::TouchEventFilter(QObject *parent) : QObject(parent) {}

bool TouchEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease ||
        event->type() == QEvent::MouseButtonPress ||
        event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        qDebug() << "Mouse event at" << mouseEvent->pos();

        QTouchEvent::TouchPoint touchPoint;
        touchPoint.setId(0);  // Идентификатор касания
        touchPoint.setPos(mouseEvent->pos());
        touchPoint.setScreenPos(mouseEvent->globalPos());
        touchPoint.setPressure(1.0);  // Просто для примера, можно уточнить значение
        QList<QTouchEvent::TouchPoint> touchPoints;
        touchPoints.append(touchPoint);

//        QTouchDevice *device = new QTouchDevice();

////        device->setType(QTouchDevice::TouchScreen);

////        device->setCapabilities(QTouchDevice::Position | QTouchDevice::Pressure);


////        QTouchEvent *touchEvent = new QTouchEvent(
////            QEvent::TouchBegin,
////            device,
////            Qt::NoModifier,
////            Qt::TouchPointPressed,
////            touchPoints
////        );
////        qApp->sendEvent(obj, touchEvent);  // Отправляем событие в приложение

   }

    else if (event->type() == QEvent::TouchBegin ||
        event->type() == QEvent::TouchUpdate ||
        event->type() == QEvent::TouchEnd) {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        qDebug() << "Touch event at" << touchEvent->touchPoints().first().pos();


     }

    return QObject::eventFilter(obj, event);


}

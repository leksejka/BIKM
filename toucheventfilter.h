#pragma once


#include <QObject>
#include <QEvent>
#include <QTouchEvent>
#include <QDebug>

class TouchEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit TouchEventFilter(QObject *parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *event) override;
};


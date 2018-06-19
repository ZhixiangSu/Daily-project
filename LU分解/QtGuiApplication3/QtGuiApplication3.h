#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication3.h"
#include<QTextEdit>
#include<QDropEvent>
#include<QDragEnterEvent>
#include<QMimedata>
#include<QDebug>
#include"LU.h"
class QtGuiApplication3 : public QMainWindow
{
	Q_OBJECT

public:
	friend class LU;
	QtGuiApplication3(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication3Class ui;
	void dragEnterEvent(QDragEnterEvent * event);
	void dropEvent(QDropEvent *event);
};

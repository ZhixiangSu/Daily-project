#include "QtGuiApplication3.h"
#include <QtWidgets/QApplication>
#include"LU.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication3 w;
	w.show();
	return a.exec();
}

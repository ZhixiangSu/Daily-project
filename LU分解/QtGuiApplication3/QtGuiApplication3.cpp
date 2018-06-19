#include "QtGuiApplication3.h"

QtGuiApplication3::QtGuiApplication3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);

}
void QtGuiApplication3::dragEnterEvent(QDragEnterEvent *event)
{
	//如果为文件，则支持拖放
	qDebug() << event->mimeData();
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}
void QtGuiApplication3::dropEvent(QDropEvent *event)
{
	//注意：这里如果有多文件存在，意思是用户一下子拖动了多个文件，而不是拖动一个目录
	//如果想读取整个目录，则在不同的操作平台下，自己编写函数实现读取整个目录文件名
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
		return;

	//往文本框中追加文件名
	foreach(QUrl url, urls) {
		QString file_name = url.toLocalFile();
//		QByteArray ss = file_name.toLatin1();
//		char* in = ss.data();
		QString ans=file_name.split(".")[0]+"_Answer."+ file_name.split(".")[1];
//		QByteArray ss2 = ans.toLatin1();
//		char* out = ss2.data();
		LU lu(file_name,ans);
		lu.getAnswer();
		QMessageBox *mes = new QMessageBox();
		mes->setText("finish");
		mes->show();
	}
}
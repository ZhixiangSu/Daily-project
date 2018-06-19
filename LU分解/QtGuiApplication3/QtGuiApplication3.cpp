#include "QtGuiApplication3.h"

QtGuiApplication3::QtGuiApplication3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setAcceptDrops(true);

}
void QtGuiApplication3::dragEnterEvent(QDragEnterEvent *event)
{
	//���Ϊ�ļ�����֧���Ϸ�
	qDebug() << event->mimeData();
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}
void QtGuiApplication3::dropEvent(QDropEvent *event)
{
	//ע�⣺��������ж��ļ����ڣ���˼���û�һ�����϶��˶���ļ����������϶�һ��Ŀ¼
	//������ȡ����Ŀ¼�����ڲ�ͬ�Ĳ���ƽ̨�£��Լ���д����ʵ�ֶ�ȡ����Ŀ¼�ļ���
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
		return;

	//���ı�����׷���ļ���
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
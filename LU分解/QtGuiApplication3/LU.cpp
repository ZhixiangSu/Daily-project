#include "LU.h"



LU::LU(QString  in, QString out)
{
	this->in = in;
	this->out = out; 
	/*
	QByteArray ss = in.toLatin1();
	fin= ss.data();
	QByteArray ss2 = out.toLatin1();
	fout= ss2.data();
	qDebug() << fin << endl;
	*/
	f1=new QFile(in);
	f1->open(QIODevice::ReadWrite);
	f2 = new QFile(out);
	f2->open(QIODevice::ReadWrite);
	Qcin = new QTextStream(f1);
	Qcout = new QTextStream(f2);
}

void LU::getAnswer()
{
	/*
	freopen(fin, "r", stdin);
	freopen(fout, "w", stdout);
	*/
	//*Qcout << "1231313";
	*Qcin >> min;
	m = min;
	n = min;
	Qcin->readLine();
	for (int i = 0; i < m; i++)
	{
		matrix.push_back(*new vector<double>);
		transform.push_back(i);
		QString s = Qcin->readLine();
		for (int j = 0; j < n; j++)
		{
			int x=s.split(",")[j].toInt();
			matrix[i].push_back(x);
		}
	}
	resolve();
}
void LU::resolve()
{
	vector<double>l, uT;
	for (int i = 0; i < min; i++)
	{
		for (int j = 0; j < i; j++)
		{
			l.push_back(0);
			uT.push_back(0);
		}
		if (matrix[transform[i]][i] == 0)
		{
			for (int j = i; j < min; j++)
			{
				if (matrix[transform[j]][i] != 0)
				{
					int temp = transform[i];
					transform[i] = transform[j];
					transform[j] = temp;
					break;
				}
				if (j == min - 1)
				{
					*Qcout << "cannot be resolved" << endl;
					return;
				}
			}
		}
		for (int j = i; j<min; j++)
		{
			l.push_back(matrix[transform[j]][i] / matrix[transform[i]][i]);
			if (j != i)matrix[transform[j]][i] /= matrix[transform[i]][i];
			uT.push_back(matrix[transform[i]][j]);
		}
		for (int j = i + 1; j < min; j++)
		{
			for (int k = i + 1; k < min; k++)
			{
				matrix[transform[j]][k] -= l[j] * uT[k];

			}
		}
		l.clear();
		uT.clear();
	}
	*Qcout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <n; j++)
		{
			if (j == i)*Qcout << "1,";
			else if (j > i)*Qcout << "0,";
			else *Qcout << matrix[transform[i]][j] << ",";
		}
		*Qcout << endl;
	}
	*Qcout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)*Qcout << "0,";
			else *Qcout << matrix[transform[i]][j] << ",";
		}
		*Qcout << endl;
	}
	*Qcout << endl;
	*Qcout << endl;
	for (int i = 0; i < min; i++)
	{
		if (i<transform[i])
		{
			*Qcout << "swap" << i << "," << transform[i] << endl;
		}
	}
}

LU::~LU()
{
}

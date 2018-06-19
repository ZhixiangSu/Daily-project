#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#define MIN(m,n) m<n?m:n
using namespace std;
class LU
{
public:
	LU(QString  in, QString out);
	void getAnswer();
	void resolve();
	~LU();
	vector<vector<double>> matrix;
	vector<vector<double>> matrix2;
	int n, m;
	int min;
	vector<int>transform;
	QString in, out;
	QFile* f1,* f2;
	QTextStream *Qcin,*Qcout;
	char* fin, *fout;
};


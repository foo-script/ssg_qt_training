#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->normalView->setModel(&m_model); // bez modyfikacji

	m_proxy.setSourceModel(&m_model);   // modyfikator
	ui->transposedView->setModel(&m_proxy);
}

MainWindow::~MainWindow()
{
	delete ui;
}

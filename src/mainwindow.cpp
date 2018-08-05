#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "call_back.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto qwidget=ui->centralWidget->findChild<QObject*>("m_pushbutton");

    //ui->find(on_actionExit_triggered)
    connect(qwidget , SIGNAL (released()),this, SLOT (on_pushbutton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_pushbutton()
{
    f(this,1); 
}
extern "C" int call_M_foo(MainWindow* m, int i) { return m->foo(i); }
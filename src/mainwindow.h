#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

typedef struct s7_scheme s7_scheme;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int foo( int i ) { return i; }
private slots:
    void on_actionExit_triggered();
    void on_pushbutton();
private:
    Ui::MainWindow *ui;
    s7_scheme *env;
	
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_selectFolder_released();

    void on_fsortfunc_released();

    void on_imageFiles_released();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QStringList files;
};

#endif // MAINWINDOW_H

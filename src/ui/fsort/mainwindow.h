#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <libfsort.h>
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
//vector<vector<double>> extract_embeddings(vector<string> image_files,int accuracy_level=_ACCURACY_LOW);

#endif // MAINWINDOW_H

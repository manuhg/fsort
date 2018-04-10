#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "libfsort.h"
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_selectFolder_released();

    void on_fsortfunc_released();

    void on_imageFiles_released();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QStringList files;
    int accuracy_level;
    QVector<double> points;
    QVector<string> vfiles;
};
//vector<vector<double>> extract_embeddings(vector<string> image_files,int accuracy_level=_ACCURACY_LOW);
#endif // MAINWINDOW_H

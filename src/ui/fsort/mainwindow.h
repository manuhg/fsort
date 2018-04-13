#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "deps.h"
#include "mappings.h"

using namespace std;

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
    int accuracy_level=1;
    int no_of_files=0;
    std::vector<std::vector<double>> points;
    std::vector<string> image_files;
    Mappings *output_window;
};
//vector<vector<double>> extract_embeddings(vector<string> image_files,int accuracy_level=_ACCURACY_LOW);
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QFileDialog>
#include<QFileIconProvider>
#include<QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new QStandardItemModel;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_selectFolder_released()
{
   int i;
   QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
   QDir directory(dir);
   QStringList temp=directory.entryList(QStringList() << "*.jpg" << "*.JPG" <<"*.png" <<"*.PNG" <<"*.xpm" <<"*.XPM",QDir::Files);
   for(i=0;i<temp.size();i++)
   {
       files.append(dir+"/"+temp.at(i));
       QFileInfo fileinfo(files.at(i));
       QFileIconProvider iconprovider;
       QIcon icon = iconprovider.icon(fileinfo);
       QStandardItem *s_item=new QStandardItem(icon,temp.at(i));
       model->appendRow(s_item);
   }
       ui->listView->setModel(model);
}
void MainWindow::on_fsortfunc_released()
{
    //extract_embeddings(,1);
}

void MainWindow::on_imageFiles_released()
{
    int i;
    QStringList temp=QFileDialog::getOpenFileNames(this,"Select Image Files","","Images (*.png *.xpm *.jpg *.JPG *.PNG *.XPM)");
    files.append(temp);
    for(i=0;i<temp.size();i++)
    {
        QFileInfo fileinfo(temp.at(i));
        QFileIconProvider iconprovider;
        QIcon icon = iconprovider.icon(fileinfo);
        QStandardItem *s_item=new QStandardItem(icon,temp.at(i));
        model->appendRow(s_item);
    }
    ui->listView->setModel(model);

}

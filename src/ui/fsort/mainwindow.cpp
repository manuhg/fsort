#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
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
   no_of_files+=temp.size();
   for(i=0;i<temp.size();i++)
   {
       files.append(dir+"/"+temp.at(i));
       QFileInfo fileinfo(files.at(i));
       QFileIconProvider iconprovider;
       QIcon icon = iconprovider.icon(fileinfo);
       QStandardItem *s_item=new QStandardItem(icon,temp.at(i));
       model->appendRow(s_item);
       image_files.push_back((dir+"/"+temp.at(i)).toStdString());
   }
       ui->listView->setModel(model);
}

void MainWindow::on_fsortfunc_released()
{
  int i;
  points=(extract_embeddings(image_files,30,3,false,80,false));
//  for(i=0;i<no_of_files;i++)
//       for(int j=0;j<2;j++)
//           points[i][j]*=2000;
  qInfo() << "\n"<<points<<"\nPlotting images..";
  QMap<QString,QVector<double>> map;
  for(i=0;i<no_of_files;i++)
      map.insert(QString::fromStdString(image_files.at(i)),QVector<double>::fromStdVector(points[i]));
  output_window=new Mappings(this,&map);
  output_window->show();
  hide();
}

void MainWindow::on_imageFiles_released()
{
    int i;
    QStringList temp=QFileDialog::getOpenFileNames(this,"Select Image Files","","Images (*.png *.xpm *.jpg *.JPG *.PNG *.XPM)");
    no_of_files+=temp.size();
    files.append(temp);
    for(i=0;i<temp.size();i++)
    {
        QFileInfo fileinfo(temp.at(i));
        QFileIconProvider iconprovider;
        QIcon icon = iconprovider.icon(fileinfo);
        QStandardItem *s_item=new QStandardItem(icon,temp.at(i));
        model->appendRow(s_item);
        image_files.push_back((temp.at(i)).toStdString());
    }
    ui->listView->setModel(model);

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
  if(arg1=="Low")
      accuracy_level=1;
  else if(arg1=="Medium")
     accuracy_level=2;
  else if(arg1=="High")
     accuracy_level=3;
}

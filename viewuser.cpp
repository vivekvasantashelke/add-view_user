#include "viewuser.h"
#include "ui_viewuser.h"
#include<QListWidget>
#include<QListWidgetItem>
#include <QTableWidgetItem>
#include <QMessageBox>
viewuser::viewuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewuser)
{
    ui->setupUi(this);


    QFile file("F:/akashQT_task/LMS3/adduser.xls");
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this,"WARNING","File NOt Open");
    }
    if(file.pos()==0)
    {
        QTextStream out(&file);
        QString text1= "Name";
        QString text2= "E-mail";
        QString text3= "MO.No";
        out<<text1<<"\t"<<text2<<"\t"<<text3<<"\n";

    QString view = out.readAll();
       ui->textEdit->setText(view);
    }

file.close();

}

viewuser::~viewuser()
{
    delete ui;
}


void viewuser::showstudents(QSet<QString>v2, int cnt,QString s)
{    //model = new QStandardItemModel(this);

     //   QListWidgetItem *item = ui->listWidget->currentItem();
       // item=new QListWidgetItem();
//        //QSet<QString>
//        for( auto str:v2)
//        {
//            item->setText(str);
//            ui->listWidget->addItem(str);

//        }
//        for( auto str:v2)
//        {
//            for(int i=0;i<cnt;i++)
//            {
//                for(int j=0;j<3;j++)
//                {
//                    QModelIndex index=model->index(i,j,QModelIndex());
//                    model->setData(index,str);
//            item->setText(str);
//           // ui->listWidget->addItem(str);
//           // model()->setData(cnt,0);
//            ui->tableWidget->model();
//        }
//            }
//        }

    }


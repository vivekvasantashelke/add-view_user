#include "searchbook.h"
#include "ui_searchbook.h"
#include"addbookss.h"
#include<QMessageBox>
//#include"addbookss.cpp"
#include"appmainpage.cpp"
//#include"adduser.h"
#include"QMultiMap"
#include"returnbook.h"
int set=0;
searchbook::searchbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchbook)
{
    ui->setupUi(this);
        QString s1;

        QFile file("F:/akashQT_task/LMS3/adduser.xls");
        if(!file.open(QFile::ReadOnly))
        {
         QMessageBox::warning(this,"Warnig","file Not Open");
        }

             if(file.pos()==0)
        {


                QTextStream out(&file);
             while(!out.atEnd())
                  {
                   QString view = out.readLine();
                   sl=view.split("\t");
                   s1=sl.at(0);
              ui->comboBox_student->addItem(s1);

              }


    file.close();



}

}

searchbook::~searchbook()
{
    delete ui;
}

void searchbook::on_pushButton_searchbook_clicked()
{
    QString book=ui->lineEdit_bookname->text();
    QString student=ui->comboBox_student->currentText();
    returnbook rb;
//    addbookss ab;
//    if(ab.trysearch(book))
//    {
    rb.filldetails(book,student);
    if(student=="Select student")
        QMessageBox::warning(this,"warning","student is not selected ");
    else
    {
            addbookss oadd;
        if(oadd.trysearch(book)==0)
        {
          QMessageBox::warning(this,"warning","book is not available");
        // exit(0);
        }
          else
        {
            oadd.issuesearched(book);
        QMessageBox::information(this,"succesffull","book is issued");
        ui->lineEdit_bookname->clear();
        }


    }
//    }


}

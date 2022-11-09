#include "adduser.h"
#include "qvalidator.h"
#include "ui_adduser.h"
#include<QSet>
#include <QMessageBox>
#include <iostream>
#include <string>
#include<cstring>
#include <Qt>
#include <QFile>

using namespace std;
QSet <QString> user,user1,user12,user123;
adduser::adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
    ui->lineEdit_mono->setValidator(new QIntValidator(0,1000000000,this));

}

int adduser::trystudent(QString student)
{

    if(user.contains(student))
    {
        return 1;
    }
    else
        return 0;

}


adduser::~adduser()
{
    delete ui;
}

void adduser::on_pushButton_addstudent_clicked()
{
    int j,i,k,l,cnt=0,l2,l3;
    string str;
    QString u,str2,u2;
   u2=ui->lineEdit_addstudent->text();
     u=ui->lineEdit_mono->text();
     str2 = ui->lineEdit_email->text();

   l3=u2.length();

   if(l3>5)
   {
       user1.insert(u2);
       ++cnt;
   }
   else
   {
       QMessageBox::warning(this,"WARNING","Please ADD FULL NAME");
   }

l2=str2.length();
     str = str2.toStdString();
     j=str.find_last_of(".");
      i=str.find_last_of("@");
       k=str.find_last_of("@gmail.com");

     if((j<0) && (i<0) && (k<0) && l2<10)
    {

         QMessageBox::warning(this,"Email","Re-Enter Email");
   ui->lineEdit_email->clear();
    }
    else
     {
       user12.insert(str2);
        ++cnt;
     }

     l= u.length();
         if(l<10 )
      {

          QMessageBox::warning(this,"MOBILE","Re-Enter MO.NO");
           ui->lineEdit_mono->clear();
      }
      else {


          user123.insert(u);
          ++cnt;
      }



         QFile file("F:/akashQT_task/LMS3/adduser.xls");
         if(!file.open(QFile::ReadOnly))
         {
             QMessageBox::warning(this,"WARNING","File NOt Open");
         }

              if(file.pos()==0)
         {


                 QTextStream out(&file);
              while(!out.atEnd())
                   {
                    QString view = out.readLine();
                if((u2+"\t"+str2+"\t"+u)==view)
                      {
                         QMessageBox::warning(this,"warning","Alearedy exixsting");
                         ++cnt;
                      }
                   }

         }


     file.close();

if(cnt==3)
{
            QFile file("F:/akashQT_task/LMS3/adduser.xls");
      if(!file.open(QFile::WriteOnly|QFile::Append))
      {
          QMessageBox::warning(this,"WARNING","File not Open");
      }
      else
      {

          QTextStream Out(&file);
          Out<<u2<<"\t"<<str2<<"\t"<<u<<"\n";
          file.close();
          close();
      }
      QMessageBox::information(this,"ADD","STUDENTS ADDED");
      cnt=0;
}
else{
  QMessageBox::information(this,"ADD","SOMETING WENT WRONG");
        cnt=0;
}
     ui->lineEdit_addstudent->clear();
      ui->lineEdit_email->clear();
       ui->lineEdit_mono->clear();







}

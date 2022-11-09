#ifndef VIEWUSER_H
#define VIEWUSER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
namespace Ui {
class viewuser;
}

class viewuser : public QDialog
{
    Q_OBJECT

public:
    explicit viewuser(QWidget *parent = nullptr);
    ~viewuser();
    void showstudents(QSet<QString>,int,QString);
private slots:
    void on_textEdit_copyAvailable(bool b);

private:
    Ui::viewuser *ui;
 QStandardItemModel *model;
};

#endif // VIEWUSER_H

#ifndef DBQUERY_H
#define DBQUERY_H
#include<QObject>
#include<QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class dbquery: public QObject
{
    Q_OBJECT
public:
    explicit dbquery(QObject *parent = nullptr);
    ~dbquery();
    Q_INVOKABLE QString displaytable();
    Q_INVOKABLE void insertdata(QString,QString,QString);// insering data as id, name and email
    Q_INVOKABLE void deletedata(int); // deleting data w.r.t to id attribute
private:
    QSqlDatabase db;
};

#endif // DBQUERY_H

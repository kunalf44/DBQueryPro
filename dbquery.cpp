#include "dbquery.h"


dbquery::dbquery(QObject *parent) : QObject(parent){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");//host -> awsurl
    db.setDatabaseName("testDB");//db name-> aws db name
    db.setUserName("kunal");// user login
    db.setPassword("Kunal123*");
    bool ok=db.open();
    if(ok){
         qDebug() << "Database is connected.";
    }
    else{
        qDebug() << "Error opening the database:" << db.lastError().text();
    }
}

dbquery::~dbquery(){
    db.close();
}

Q_INVOKABLE QString dbquery::displaytable(){
    QString output="";
    QSqlQuery query("SELECT * FROM Author");  // Replace 'your_table' with the actual table name
    while (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString email = query.value(2).toString();
        qDebug() << "ID:" << id << ", Name:" << name << ", Email:"<<email;
        output+= "ID:" + id + ", Name:" + name + ", Email:"+email + "\n";
    }
    return output;
}

Q_INVOKABLE void dbquery::insertdata(QString id,QString name,QString email){

    QSqlQuery querry;
    querry.prepare("INSERT INTO Author (id, name, email) VALUES (:id, :name, :email)");
    querry.bindValue(":id", id);
    querry.bindValue(":name", name );
    querry.bindValue(":email",email );
    qDebug()<<querry.exec();

    qDebug()<<id<<name<<email<<"done";
}

Q_INVOKABLE void dbquery::deletedata(int id){

    QSqlQuery query("DELETE FROM Author WHERE id="+QString::number(id));

}

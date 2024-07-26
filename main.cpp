#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <dbquery.h>

int main(int argc, char *argv[])
{
    // qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);
    // dbquery db;
    // db.insertdata(5,"Abhi","abh@gmail.com");
    // db.deletedata(5);
    qmlRegisterType<dbquery>("Db",1,0,"Db");
    // db.displaytable();
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/DBQueryPro/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

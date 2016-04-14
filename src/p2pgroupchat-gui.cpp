#include <QApplication>
#include <QFile>
#include "mainwindow.h"
#include "defines.h"

void setStyleSheet(QApplication &app, QString filename){
    QFile file(filename);
    if(file.open(QFile::ReadOnly)){
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(QString::fromStdString(p2pgc_gui::PROJECT_NAME));
    a.setApplicationDisplayName(QString::fromStdString(p2pgc_gui::PROJECT_NAME + " " + p2pgc_gui::PROJECT_VERSION));
    a.setApplicationVersion(QString::fromStdString(p2pgc_gui::PROJECT_VERSION));

    setStyleSheet(a, "style.qss");

    MainWindow w;
    w.show();

    return a.exec();
}

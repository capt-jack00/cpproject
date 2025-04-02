#include <QApplication>
#include <QMainWindow>
#include <QString>

QString projectName = "qtpro";
int main(int argc, char *argv[]){
QApplication app(argc, argv);

QMainWindow mainWindow;
mainWindow.setWindowTitle(projectName);
mainWindow.resize(800, 600);
mainWindow.show();

return app.exec();

}
#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("Lutix - Qt Demo");

    // Create a tab widget
    QTabWidget *tabWidget = new QTabWidget(&window);

    // Create three tabs
    QWidget *mainTab = new QWidget();
    QWidget *p2poolTab = new QWidget();
    QWidget *xmrigTab = new QWidget();

    // Add widgets to each tab
    QLabel *mainLabel = new QLabel("Main Tab Content", mainTab);
    QLabel *p2poolLabel = new QLabel("P2Pool Tab Content", p2poolTab);
    QLabel *xmrigLabel = new QLabel("XMRig Tab Content", xmrigTab);

    // Add tabs to the tab widget
    tabWidget->addTab(mainTab, "Main");
    tabWidget->addTab(p2poolTab, "P2Pool");
    tabWidget->addTab(xmrigTab, "XMRig");

    // Add the tab widget to the main window's central widget
    window.setCentralWidget(tabWidget);

    // Show the main window
    window.show();

    // Run the application event loop
    return app.exec();
}

#include <QtWidgets>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("Lutix");
    window.resize(800, 600); // Set the size of the window

    // Create a tab widget
    QTabWidget *tabWidget = new QTabWidget(&window);

    // Create three tabs
    QWidget *mainTab = new QWidget();
    QWidget *p2poolTab = new QWidget();
    QWidget *xmrigTab = new QWidget();

    // Add widgets to each tab
    QLabel *mainLabel = new QLabel("Lutix :3\n(Made by a tranny and a furry)", mainTab);

    // Create buttons for the p2pool tab
    QPushButton *startButton = new QPushButton("Start", p2poolTab);
    QPushButton *stopButton = new QPushButton("Stop", p2poolTab);
    QPushButton *restartButton = new QPushButton("Restart", p2poolTab);

    // Layout for buttons
    QVBoxLayout *layout = new QVBoxLayout(p2poolTab);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    layout->addWidget(restartButton);
    p2poolTab->setLayout(layout);

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

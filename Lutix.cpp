#include <QtWidgets>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

// Function to save wallet address to settings.json
void saveWalletAddress(const QString &walletAddress) {
    QJsonObject jsonObject;
    jsonObject["wallet_address"] = walletAddress;

    QJsonDocument jsonDocument(jsonObject);

    QFile file("settings.json");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open settings.json for writing.");
        return;
    }

    file.write(jsonDocument.toJson());
    file.close();
}

// Function to read wallet address from settings.json
QString readWalletAddress() {
    QFile file("settings.json");
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "Error", "Failed to open settings.json for reading.");
        return "";
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = jsonDocument.object();

    if (jsonObject.contains("wallet_address")) {
        return jsonObject["wallet_address"].toString();
    } else {
        return "";
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow window;
    window.setWindowTitle("Lutix - BETA");
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
    QPushButton *saveButton = new QPushButton("Save", p2poolTab);

    // Layout for buttons
    QVBoxLayout *p2poolLayout = new QVBoxLayout(p2poolTab);
    p2poolLayout->addWidget(startButton);
    p2poolLayout->addWidget(stopButton);

    // Add QLineEdit for XMR wallet address
    QLineEdit *walletAddressEdit = new QLineEdit(p2poolTab);
    walletAddressEdit->setPlaceholderText("Enter XMR Wallet Address");
    p2poolLayout->addWidget(walletAddressEdit);

    // Add a frame with a terminal-like interface for P2Pool output
    QFrame *terminalFrame = new QFrame(p2poolTab);
    QPlainTextEdit *terminalTextEdit = new QPlainTextEdit(terminalFrame);
    terminalTextEdit->setReadOnly(true);
    terminalTextEdit->setPlaceholderText("P2Pool output will appear here...");
    QVBoxLayout *terminalLayout = new QVBoxLayout(terminalFrame);
    terminalLayout->addWidget(terminalTextEdit);
    terminalFrame->setLayout(terminalLayout);
    p2poolLayout->addWidget(terminalFrame);

    // Connect the restart button to save wallet address to settings.json
    QObject::connect(restartButton, &QPushButton::clicked, [&]() {
        QString walletAddress = walletAddressEdit->text();
        saveWalletAddress(walletAddress);
    });

    // Connect the save button to save wallet address to settings.json
    QObject::connect(saveButton, &QPushButton::clicked, [&]() {
        QString walletAddress = walletAddressEdit->text();
        saveWalletAddress(walletAddress);
    });

    // Read wallet address from settings.json
    QString savedWalletAddress = readWalletAddress();
    walletAddressEdit->setText(savedWalletAddress);

    p2poolLayout->addWidget(saveButton);
    p2poolTab->setLayout(p2poolLayout);

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

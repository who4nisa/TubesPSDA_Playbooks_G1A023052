#include "user.h" // Termasuk header file untuk kelas User yang menyediakan antarmuka pengguna
#include "ui_user.h" // Termasuk header file untuk antarmuka UI User
#include <QMessageBox> // Termasuk header file untuk menampilkan kotak pesan
#include <QStandardItemModel>

User::User(LinkedList* sharedList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User), // Membuat antarmuka UI baru untuk kelas User
    linkedList(sharedList) // Inisialisasi dengan sharedList
{
    ui->setupUi(this); // Menyiapkan antarmuka UI

    connect(ui->searchButton, &QPushButton::clicked, this, &User::search); // Menghubungkan klik tombol search dengan metode search()
}

User::~User() {
    delete ui; // Menghapus antarmuka UI
    delete linkedList; // Menghapus objek LinkedList
}

void User::search() {
    QString judulSearch = ui->judulLineEdit->text(); // Mendapatkan teks dari judulLineEdit

    Node* bukuNode = linkedList->find(judulSearch); // Mencari buku dalam LinkedList
    if (bukuNode != nullptr) {

        // Membuat model baru untuk menampilkan hasil pencarian
        QStandardItemModel *searchResultModel = new QStandardItemModel(1, 4, this);

        // Mengatur judul kolom
        searchResultModel->setHorizontalHeaderLabels(QStringList() << "Judul" << "Penerbit" << "Tahun Terbit" << "Sinopsis");

        // Menambahkan data hasil pencarian ke dalam model
        searchResultModel->setItem(0, 0, new QStandardItem(bukuNode->judul));
        searchResultModel->setItem(0, 1, new QStandardItem(bukuNode->penerbit));
        searchResultModel->setItem(0, 2, new QStandardItem(QString::number(bukuNode->tahunTerbit)));
        searchResultModel->setItem(0, 3, new QStandardItem(bukuNode->sinopsis));

        // Mengatur model untuk QTableView
        ui->outputTableView->setModel(searchResultModel);


    }
    else {
        QMessageBox::warning(this, "Peringatan", "Buku tidak ada di dalam daftar!");
    }
}

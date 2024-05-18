#include "admin.h" // Termasuk header file untuk kelas Admin
#include "ui_admin.h" // Termasuk header file untuk antarmuka UI Admin
#include <QMessageBox> // Mengimpor header file untuk MessageBox

Admin::Admin(LinkedList* sharedList, QWidget *parent) :
    QMainWindow(parent), // Memanggil konstruktor kelas induk QMainWindow
    ui(new Ui::Admin), // Membuat objek antarmuka UI baru untuk Admin
    linkedList(sharedList), // Inisialisasi dengan sharedList
    model(new QStandardItemModel(this)) // Membuat objek model baru dari QStandardItemModel
{
    ui->setupUi(this); // Menyiapkan antarmuka UI yang telah dibuat sebelumnya

    // Menghubungkan sinyal dan slot untuk tombol-tombol
    connect(ui->CreateButton, &QPushButton::clicked, this, &Admin::createBuku);
    connect(ui->ReadButton, &QPushButton::clicked, this, &Admin::readBuku);
    connect(ui->UpdateButton, &QPushButton::clicked, this, &Admin::updateBuku);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &Admin::deleteBuku);

    // Menetapkan model untuk TableView
    ui->tableView->setModel(model);
    // Menetapkan judul kolom untuk model
    model->setHorizontalHeaderLabels(QStringList() << "Judul" << "Penerbit" << "Tahun Terbit" << "Sinopsis");
}

Admin::~Admin() {
    delete ui; // Menghapus objek antarmuka UI
    delete linkedList; // Menghapus objek LinkedList
    delete model; // Menghapus objek model
}

void Admin::createBuku() {
    QString judul = ui->judulLineEdit->text(); // Mendapatkan judul dari input
    QString penerbit = ui->penerbitLineEdit->text(); // Mendapatkan penerbit dari input
    int tahunTerbit = ui->tahunterbitLineEdit->text().toInt(); // Mendapatkan tahun terbit dari input
    QString sinopsis = ui->sinopsisLineEdit->text(); // Mendapatkan sinopsis dari input

    // Memeriksa apakah buku sudah ada dalam daftar
    if (linkedList->find(judul) != nullptr) {
        QMessageBox::warning(this, "Peringatan", "Buku sudah ada dalam daftar!"); // Menampilkan pesan peringatan jika buku sudah ada
        return;
    }

    // Menambahkan buku baru ke dalam linked list
    linkedList->insert(judul, penerbit, tahunTerbit, sinopsis);

    // Menambahkan data ke dalam model
    QList<QStandardItem*> rowData;
    rowData << new QStandardItem(judul)
            << new QStandardItem(penerbit)
            << new QStandardItem(QString::number(tahunTerbit))
            << new QStandardItem(sinopsis);
    model->appendRow(rowData);

    QMessageBox::information(this, "Sukses", "Buku berhasil ditambahkan!"); // Menampilkan pesan informasi bahwa buku berhasil ditambahkan
}

void Admin::updateBuku() {
    QString judulToUpdate = ui->judulLineEdit->text(); // Mendapatkan judul buku yang akan diperbarui
    QString penerbit = ui->penerbitLineEdit->text(); // Mendapatkan penerbit buku yang akan diperbarui
    int tahunTerbit = ui->tahunterbitLineEdit->text().toInt(); // Mendapatkan tahun terbit buku yang akan diperbarui
    QString sinopsis = ui->sinopsisLineEdit->text(); // Mendapatkan sinopsis buku yang akan diperbarui

    Node* bukuNode = linkedList->find(judulToUpdate); // Mencari node buku berdasarkan judul
    if (bukuNode) { // Jika buku ditemukan
        bukuNode->penerbit = penerbit; // Memperbarui penerbit buku
        bukuNode->tahunTerbit = tahunTerbit; // Memperbarui tahun terbit buku
        bukuNode->sinopsis = sinopsis; // Memperbarui sinopsis buku

        QMessageBox::information(this, "Sukses", "Informasi buku berhasil diperbarui!"); // Menampilkan pesan informasi bahwa informasi buku berhasil diperbarui
        readBuku(); // Memperbarui tampilan dengan data terbaru
    } else {
        QMessageBox::warning(this, "Peringatan", "Buku tidak ditemukan!"); // Menampilkan pesan peringatan jika buku tidak ditemukan
    }
}

void Admin::deleteBuku() {
    QString judulToDelete = ui->judulLineEdit->text(); // Mendapatkan judul buku yang akan dihapus

    if (linkedList->remove(judulToDelete)) { // Jika buku berhasil dihapus
        QMessageBox::information(this, "Sukses", "Buku berhasil dihapus!"); // Menampilkan pesan informasi bahwa buku berhasil dihapus
        readBuku(); // Memperbarui tampilan dengan data terbaru
    } else {
        QMessageBox::warning(this, "Peringatan", "Buku tidak ditemukan!"); // Menampilkan pesan peringatan jika buku tidak ditemukan
    }
}

void Admin::readBuku() {
    // Membersihkan model sebelum menambahkan data baru
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "Judul" << "Penerbit" << "Tahun Terbit" << "Sinopsis");

    // Memperbarui tampilan dengan data terbaru
    Node* currentNode = linkedList->getHead(); // Mendapatkan node pertama dari linked list
    while (currentNode != nullptr) { // Selama masih ada node yang tersedia
        QList<QStandardItem*> rowData; // Membuat list item data
        rowData << new QStandardItem(currentNode->judul)
                << new QStandardItem(currentNode->penerbit)
                << new QStandardItem(QString::number(currentNode->tahunTerbit))
                << new QStandardItem(currentNode->sinopsis);
        model->appendRow(rowData); // Menambahkan baris data ke dalam model

        currentNode = currentNode->next; // Pindah ke node berikutnya
    }
}

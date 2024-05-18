#include "playbooks.h" // Mengimpor file header playbooks.h
#include "ui_playbooks.h" // Mengimpor file header ui_playbooks.h
#include <QMessageBox>

Playbooks::Playbooks(QWidget *parent) : // Konstruktor untuk kelas Playbooks
    QMainWindow(parent), // Memanggil konstruktor kelas induk QMainWindow
    ui(new Ui::Playbooks) // Membuat objek UI baru
{
    ui->setupUi(this); // Mengatur tata letak UI yang didefinisikan di file .ui
    connect(ui->loginButton, &QPushButton::clicked, this, &Playbooks::onLoginButtonClicked); // Menghubungkan klik tombol login dengan metode onLoginButtonClicked

    // Inisialisasi userList di sini
    userList.insert("admin", "password"); // Menambahkan pengguna admin ke userList dengan kata sandi "password"
    userList.insert("user1", "pass1"); // Menambahkan pengguna user1 ke userList dengan kata sandi "pass1"

}

Playbooks::~Playbooks() { // Destruktor untuk kelas Playbooks
    delete ui; // Menghapus objek UI
}

void Playbooks::onLoginButtonClicked() { // Implementasi metode onLoginButtonClicked
    QString username = ui->usernameEdit->text(); // Mendapatkan nama pengguna dari input usernameEdit
    QString password = ui->passwordEdit->text(); // Mendapatkan kata sandi dari input passwordEdit

    if (username.isEmpty() || password.isEmpty()) { // Memeriksa apakah nama pengguna atau kata sandi kosong
        QMessageBox::warning(this, "Warning", "Username or password cannot be empty!"); // Menampilkan peringatan jika nama pengguna atau kata sandi kosong
        return; // Keluar dari metode jika nama pengguna atau kata sandi kosong
    }

    if (userList.find(username, password)) { // Memeriksa apakah nama pengguna dan kata sandi cocok dengan yang ada di userList
        QMessageBox::information(this, "Success", "Login successful!"); // Menampilkan pesan informasi jika login berhasil

        if (username == "admin" && password == "password") {
            emit adminLogin(); // Pancarkan sinyal adminLogin
        } else {
            emit userLogin(); // Pancarkan sinyal userLogin
        }
    } else { // Jika nama pengguna atau kata sandi tidak cocok
        QMessageBox::warning(this, "Error", "Invalid username or password!"); // Menampilkan peringatan bahwa nama pengguna atau kata sandi tidak valid
    }
}

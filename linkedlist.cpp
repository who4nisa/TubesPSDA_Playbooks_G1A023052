#include "linkedList.h" // Termasuk header file LinkedList untuk mendefinisikan kelas LinkedList

LinkedList::LinkedList() : head(nullptr) {} // Implementasi konstruktor LinkedList yang menginisialisasi head dengan nullptr

LinkedList::~LinkedList() { // Implementasi destruktor LinkedList untuk menghapus semua node dari linked list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next; // Simpan pointer ke node berikutnya
        delete current; // Hapus node saat ini
        current = next; // Pindah ke node berikutnya
    }
}

void LinkedList::insert(const QString& judul, const QString& penerbit, int tahunTerbit, const QString& sinopsis) {
    Node* newNode = new Node; // Buat node baru
    newNode->judul = judul; // Isi data ke dalam node baru
    newNode->penerbit = penerbit;
    newNode->tahunTerbit = tahunTerbit;
    newNode->sinopsis = sinopsis;
    newNode->next = head; // Pasang node baru di awal linked list
    head = newNode;
}

bool LinkedList::update(const QString& judul, const QString& penerbit, int tahunTerbit, const QString& sinopsis) {
    Node* current = head;
    while (current != nullptr) { // Iterasi melalui linked list
        if (current->judul == judul) { // Jika judul buku cocok
            current->penerbit = penerbit; // Perbarui informasi buku
            current->tahunTerbit = tahunTerbit;
            current->sinopsis = sinopsis;
            return true; // Kembalikan true karena buku ditemukan dan diperbarui
        }
        current = current->next; // Pindah ke node berikutnya
    }
    return false; // Kembalikan false jika buku tidak ditemukan
}

bool LinkedList::remove(const QString& judul) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) { // Iterasi melalui linked list
        if (current->judul == judul) { // Jika judul buku cocok
            if (prev) // Jika bukan node pertama dalam linked list
                prev->next = current->next; // Skip node saat ini
            else
                head = current->next; // Jika node pertama, ubah head menjadi node berikutnya
            delete current; // Hapus node saat ini
            return true; // Kembalikan true karena buku ditemukan dan dihapus
        }
        prev = current; // Simpan node saat ini sebagai node sebelumnya
        current = current->next; // Pindah ke node berikutnya
    }
    return false; // Kembalikan false jika buku tidak ditemukan
}

Node* LinkedList::find(const QString& judul) {
    Node* current = head;
    while (current != nullptr) { // Iterasi melalui linked list
        if (current->judul == judul) // Jika judul buku cocok
            return current; // Kembalikan node yang berisi informasi buku
        current = current->next; // Pindah ke node berikutnya
    }
    return nullptr; // Kembalikan nullptr jika buku tidak ditemukan
}

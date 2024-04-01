#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string namaNya;
    int umurNya;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void inisialisasiNya() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool cekNya() {
    return head == NULL;
}

// Tambah Node di depan
void depanNya(string name, int age) {
    Node* baru = new Node;
    baru->namaNya = name;
    baru->umurNya = age;
    baru->next = NULL;

    if (cekNya()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void belakangNya(string name, int age) {
    Node* baru = new Node;
    baru->namaNya = name;
    baru->umurNya = age;
    baru->next = NULL;

    if (cekNya()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int jumlahlistNya() {
    int jumlah = 0;
    Node* hitung = head;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Tambah Node di tengah
void tengahNya(string name, int age, int posisi) {
    if (posisi < 1 || posisi > jumlahlistNya()) {
        cout << "Tidak terjangkau!" << endl;
    } else if (posisi == 1) {
        cout << "Bukan di tengah." << endl;
    } else {
        Node* baru = new Node();
        baru->namaNya = name;
        baru->umurNya = age;

        Node* bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di depan
void hapusNya() {
    if (!cekNya()) {
        Node* hapus = head;

        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }

        delete hapus;
    } else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Node di belakang
void hapusbelakangNya() {
    if (!cekNya()) {
        Node* hapus = tail;

        if (head != tail) {
            Node* bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }

        delete hapus;
    } else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Node di tengah
void hapustengahNya(int posisi) {
    if (posisi < 1 || posisi > jumlahlistNya()) {
        cout << "Tidak terjangkau!" << endl;
    } else if (posisi == 1) {
        cout << "Bukan yang tengah." << endl;
    } else {
        Node* hapus;
        Node* bantu = head;
        Node* bantu2 = nullptr;
        int nomor = 1;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah data di depan
void ubahdepanNya(string name, int age) {
    if (!cekNya()) {
        head->namaNya = name;
        head->umurNya = age;
    } else {
        cout << "Tidak ada yang berubah!" << endl;
    }
}

// Ubah data di tengah
void ubahtengahNya(string name, int age, int posisi) {
    if (!cekNya()) {
        if (posisi < 1 || posisi > jumlahlistNya()) {
            cout << "Tidak Terjangkau!" << endl;
        } else if (posisi == 1) {
            cout << "Bukan yang Tengah." << endl;
        } else {
            Node* bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->namaNya = name;
            bantu->umurNya = age;
        }
    } else {
        cout << "Kosong!" << endl;
    }
}

// Ubah data di belakang
void ubahbelakangNya(string name, int age) {
    if (!cekNya()) {
        tail->namaNya = name;
        tail->umurNya = age;
    } else {
        cout << "Kosong" << endl;
    }
}

// Hapus semua Node
void hapuslistNya() {
    Node* bantu = head;
    Node* hapus;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "Menghapus semua!" << endl;
}

// Tampilkan semua Node
void tampillistNya() {
    Node* bantu = head;

    cout << left << setw(15) << "-Nama-" << right << setw(4) << "-Usia-" << endl;

    if (!cekNya()) {
        while (bantu != NULL) {
            cout << left << setw(15) << bantu->namaNya << right << setw(4) << bantu->umurNya << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "Kosong!" << endl;
    } 
}

int main() {
    inisialisasiNya(); // Inisialisasi Linked List

    cout << "\n(A.)====== SELAMAT DATANG ======" << endl; // Menampilkan nama dan umur awal & menjawab poin a

    string nama, namaAnda;
    int usia, usiaAnda;
    cout << "Masukkan nama Anda: ";
    cin >> namaAnda;
    cout << "Masukkan usia Anda: ";
    cin >> usiaAnda;
    depanNya(namaAnda, usiaAnda);

    cout << "Masukkan nama mahasiswa lainnya:" << endl;
    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    cout << "Nama: ";
    cin >> nama;
    cout << "Usia: ";
    cin >> usia;
    belakangNya(nama, usia);

    tampillistNya();

    // Menjawab poin b
    cout << "====== (B) Hapus data 'Akechi' ======" << endl;
    hapustengahNya(6);
    tampillistNya();

    // Menjawab poin c
    cout << "====== (C) Tambah data 'Futaba (18)' diantara John & Jane ======" << endl;
    tengahNya("Futaba", 18, 3);
    tampillistNya();

    // Menjawab poin d
    cout << "====== (D) Tambah data 'Igor (20)' di awal ======" << endl;
    depanNya("Igor", 20);
    tampillistNya();

    // Menjawab poin e & f
    cout << "====== (E) Ubah data 'Michael' menjadi 'Reyn (18)' ======" << endl;
    cout << "====== (F) Tampilan Akhir ======" << endl;
    ubahtengahNya("Reyn", 18, 6);
    tampillistNya();

    return 0;
}

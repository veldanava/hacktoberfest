#include <iostream>
#include <string.h>

using namespace std;

int posisi;
struct Mahasiswa{
    string nama;
    string nim;
    int umur;

    Mahasiswa *lanjut, *previous;
};

Mahasiswa *mhsBaru, *curr, *hapus, *bantu,*bantu1, *head=NULL, *tail=NULL;

bool IsEmty(){
    if(head == NULL){
        return 1;
    }
    else 0;
}

int jumlahNode(){
    curr = head;
    int jumlah = 0;
    while(curr != NULL){
        jumlah ++;
        curr = curr->lanjut;
    }
    return jumlah;
}

void print(){
    curr = head;
    int urutan = 1;
    while(curr!=NULL){
        cout << "Node ke-" << urutan << endl;
        cout << curr->nama << endl;
        cout << curr->nim << endl;
        cout << curr->umur << endl;
        curr = curr->lanjut;
        urutan++;
        cout << endl;
    }
}

void createLinkedList(string nama, string nim, int umur){
    mhsBaru = new Mahasiswa();
    mhsBaru -> nama = nama;
    mhsBaru -> nim = nim;
    mhsBaru -> umur = umur;
    mhsBaru -> lanjut = NULL;
    mhsBaru -> previous = NULL;
    head = mhsBaru;
    tail = head;
    }

void TambahDepanLinkedList(string nama, string nim, int umur){

        mhsBaru = new Mahasiswa();
        mhsBaru -> nama = nama;
        mhsBaru -> nim = nim;
        mhsBaru -> umur = umur;
        mhsBaru -> lanjut = head;
        mhsBaru -> previous = NULL;
        head -> previous = mhsBaru;
        head = mhsBaru;

}

void TambahBelakangLinkedList(string nama, string nim, int umur){

        mhsBaru = new Mahasiswa();
        mhsBaru -> nama = nama;
        mhsBaru -> nim = nim;
        mhsBaru -> umur = umur;
        mhsBaru -> lanjut = NULL;
        mhsBaru -> previous = tail;
        tail -> lanjut = mhsBaru;
        tail = mhsBaru;

}


void HapusBelakang(){
    string d, e;
    int f;
    if(IsEmty()==0){
        if(head->lanjut != NULL){
            bantu = head;
            while(bantu->lanjut != tail){
                bantu = bantu->lanjut;
            }
            hapus = tail;
            tail -> previous = NULL;
            tail = bantu;
            tail -> lanjut = NULL;
            //d = hapus->nama;
            //e = hapus->nim;
            //f = hapus->umur;
            delete hapus;
        }
        else{
            //d = head->nama;
            //e = head->nim;
            //f = head->umur;
            head = NULL;
        }
        cout << "Data Terhapus" << endl;
    }
    else{
        cout << "Data Masih Kosong" << endl;
    }
}

void HapusDepan(){
    if(IsEmty()==0){
        if(head->lanjut != NULL){
            hapus = head;
            head = head->lanjut;
            head -> previous =  NULL;
            //d = hapus->nama;
            //e = hapus->nim;
            //f = hapus->umur;
            delete hapus;
        }
        else{
            //d = head->nama;
            //e = head->nim;
            //f = head->umur;
            head = NULL;
        }
        cout << "Data Terhapus" << endl;
    }
    else{
        cout << "Data Masih Kosong" << endl;
    }
}

void HapusAngka(string nama){
/*    curr = head;
    while(curr->nama != nama){
        curr = curr->lanjut;
        bantu = curr->previous;
        bantu1 = curr->lanjut;
    }
    if(curr->lanjut = NULL){
        hapus = curr;
        hapus->previous = NULL;
        hapus->lanjut = NULL;
        bantu->lanjut = NULL;
        delete hapus;
    }else{
      hapus = curr;
      hapus->previous = NULL;
      hapus->lanjut = NULL;
      bantu->lanjut = bantu1;
      bantu1->previous = bantu1;
      delete hapus;
    }
    cout << "Data Berhasil Dihapus" << endl;
    */
    if(head==tail){
        hapus = head;
        delete hapus;
        head = tail = NULL;
    }
    else{
         if(nama == head->nama) {
                /*hapus = head;
                head = head->lanjut;
                head->previous = NULL;
                delete hapus;*/
                HapusDepan();
            }
        else if(nama == tail->nama) {
                /*bantu = tail->previous;
                hapus = tail;
                bantu->lanjut = NULL;
                tail = bantu;
                delete hapus;*/
                HapusBelakang();
            }
        else{
            curr = head;
            while(curr!=tail){
                if(nama == curr->nama){
                    bantu = curr->previous;
                    hapus = curr;
                    bantu->lanjut = hapus->lanjut;
                    hapus->lanjut->previous = bantu;
                    delete hapus;
                }
                curr = curr->lanjut;
            }
    }

    }

}

/*void urut(){
    Mahasiswa *i, *j;
    int k;
    string l, m;
    for(i=head; i->lanjut != NULL; i=i->lanjut){
        for(j=i->lanjut; j != NULL; j=j->lanjut){
            if(i->umur > j->umur){
                k = j->umur;
                j->umur = i->umur;
                i->umur = k;

                l = j->nama;
                j->nama = i->nama;
                i->nama = l;

                m = j->nim;
                j->nim = i->nim;
                i->nim = m;
            }
        }
    }
    cout << "Data sudah diurutkan" << endl;
}


void tambahTengah(string nama, string nim, int umur, int posisi){
    if(posisi < 1 || posisi > jumlahNode()){
        cout << "Tidak bisa menambahkan node" << endl;
    }else if(posisi == 1){
        cout << "Node hanya 1" << endl;
    }
    else{
        mhsBaru = new Mahasiswa();
        mhsBaru->nama = nama;
        mhsBaru->nim = nim;
        mhsBaru->umur = umur;

        curr = head;
        int nomor = 1;
        while(nomor < posisi-1){
            curr = curr->lanjut;
            nomor++;
        }
        mhsBaru->lanjut = curr->lanjut;
        curr->lanjut = mhsBaru;

    }
}

void hapusTengah(int posisi){
    if(posisi < 1 || posisi > jumlahNode()){
        cout << "Posisi diluar jangkauan" << endl;
    }else if(posisi == 1 || posisi == jumlahNode()){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Mahasiswa *hapus, *before;
        int nomor = 1;
        curr = head;
        while(nomor <= posisi){
            if(nomor == posisi-1){
                before = curr;
            }
            if(nomor == posisi){
                hapus = curr;
            }
            curr = curr->lanjut;
            nomor++;
        }
        before->lanjut = curr;
        delete hapus;
        //cout << "Data terhapus" << endl;
}
}
*/
void Menu(){
    int pil;
    string nama, nim;
    int umur;
    cout << "=================Menu==============" << endl;
    cout << "1. Create Linked List(Hanya bisa dilakukan sekali)" << endl;
    cout << "2. Tambah Depan" << endl;
    cout << "3. Tambah Belakang" << endl;
    cout << "4. Print" << endl;
    cout << "5. Hapus Depan" << endl;
    cout << "6. Hapus Belakang" << endl;
    cout << "7. Urutkan" << endl;
    cout << "8. Tambah Tengah" << endl;
    cout << "9. Hapus Sesuai Angka" << endl;
    cout << "===================================" << endl;
    cin >>pil;
    cout << "-----------------------------------" << endl;

    if(pil == 1){
    cout << "Masukkan Nama :";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan NIM :";
    cin >> nim;
    cout << "Masukkan Umur :";
    cin >> umur;
        createLinkedList(nama, nim, umur);
        Menu();
    }
    else if(pil == 2){
    cout << "Masukkan Nama :";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan NIM :";
    cin >> nim;
    cout << "Masukkan Umur :";
    cin >> umur;
        TambahDepanLinkedList(nama, nim, umur);
        Menu();
    }
    else if(pil == 3){
    if(jumlahNode() < 1){
        cout << "Data kosong, tidak bisa input data" << endl;
        Menu();
    }
    else{
    cout << "Masukkan Nama :";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan NIM :";
    cin >> nim;
    cout << "Masukkan Umur :";
    cin >> umur;
        TambahBelakangLinkedList(nama, nim, umur);
        Menu();
    }
    }
    else if(pil==4){
        print();
        Menu();
    }
    else if(pil==5){
        HapusDepan();
        Menu();
    }
    else if(pil==6){
        HapusBelakang();
        Menu();
    }
/*
    else if(pil==7){
        urut();
        Menu();
    }
    else if(pil==8){
    if(jumlahNode() < 1){
        cout << "Data kosong, tidak bisa input data" << endl;
        Menu();
    }
    else{
        cout << "Nama : ";
        cin.ignore();
        getline(cin, nama);
        cout << "NIM : ";
        cin >> nim;
        cout << "Umur : ";
        cin >> umur;
        cout << "Posisi : ";
        cin >> posisi;
        tambahTengah(nama, nim, umur, posisi);
        Menu();
    }
    }
*/
    else if(pil==9){
        cout << "Nama : ";
        cin.ignore();
        getline(cin, nama);
        HapusAngka(nama);
        Menu();
    }
    }
int main()
{
    //createLinkedList("Reza", "A11.2021.13889", 20);
    //TambahDepanLinkedList("Reza2", "A11.2021.13889", 20);
    //TambahBelakangLinkedList("Reza3", "A11.2021.13889", 20);
    //print();
    Menu();
return 0;
}

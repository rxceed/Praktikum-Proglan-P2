#include <iostream>

using namespace std;

class Car
{
    protected:
    float Kecepatan;
    int Bensin;
    int Bensin_max;
    int Penumpang;
    
    public:
    Car()
    {
        Kecepatan = 10;
        Bensin = 100;
        Bensin_max = 100;
        Penumpang = 4;
    }
    
    virtual void jalan()
    {
        Bensin -= Kecepatan;
        cout<<"Mobil ini berjalan sejauh "<<Kecepatan<<" km/jam"<<endl;
    }
    
    virtual void angkut()
    {
        
    }
    
};

class SuperCar:public Car
{
    public:
    SuperCar():Car()
    {
        Kecepatan = 100;
        Bensin = 1000;
        Bensin_max = 1000;
    }
};

class Pickup:public Car
{
    private:
    int kapasitas;
    int kapasitas_max;
    
    public:
    Pickup():Car()
    {
        kapasitas = 1;
        kapasitas_max = 100;
    }
    Pickup(int kapasitas_, int kapasitas_max_):Car()
    {
        kapasitas = kapasitas_;
        kapasitas_max = kapasitas_max_;
    }
    
    void angkut(int berat_barang)
    {
        if(kapasitas + berat_barang <= kapasitas_max)
        {
            kapasitas += berat_barang;
            cout<<"Barang berhasil diangkut, total kapasitas saat ini: "<<kapasitas<<"/"<<kapasitas_max<<endl;
        }
        else
        {
            cout<<"Kapasitas pickup penuh"<<endl;
        }
    }
    
    void jalan() override
    {
        Kecepatan /= kapasitas;
        int konsumsi_bensin = kapasitas*2;
        Bensin -= konsumsi_bensin;
        cout<<"Mobil ini berjalan sejauh "<<Kecepatan<<" km/jam dengan kapasitas terpakai "<<kapasitas<<" kg"<<endl;
    }
    
    void turunkan(int berat_barang)
    {
        if(kapasitas - berat_barang >= 0)
        {
            kapasitas -= berat_barang;
            cout<<"Barang berhasil diturunkan, total kapasitas saat ini: "<<kapasitas<<"/"<<kapasitas_max<<endl;
        }
        else
        {
            cout<<"Pickup sudah kosong"<<endl;
        }
    }
};

int main()
{
    Car mobil_1;
    SuperCar mobil_2;
    Pickup pickup_1;
    Pickup pickup_2(20, 400);
    
    mobil_1.jalan();
    mobil_2.jalan();
    pickup_1.angkut(4);
    pickup_1.jalan();
    pickup_2.angkut(7);
    pickup_2.jalan();
    pickup_1.turunkan(2);
    pickup_2.turunkan(4);

    return 0;
}

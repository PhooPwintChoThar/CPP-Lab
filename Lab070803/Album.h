#ifndef ALBUM_H
#define ALBUM_H
#include<string>
using namespace std;

class Album{
    string title , artist;
    double price ;
    int copies ;
    static int totalAlbums;
    static double totalSales;
    public:
    Album( const string& , const string &, double, int);
    string getTitle() const;
    string getArtist() const;
    double getPrice() const;
    int getCopies() const;
    void purchaseAlbum();
    static int getTotalAlbums ();
    static double getTotalSales ();



};

#endif
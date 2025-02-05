#include "Album.h"
#include<iostream>
using namespace std;

int Album::totalAlbums=0;
double Album::totalSales=0;

Album::Album(const string& title, const string & artist, double price, int copies) 
: title(title) , artist (artist) , price (price) , copies(copies){
    totalAlbums+=copies;

}

string Album::getTitle() const{
    return title;
};

string Album::getArtist() const{
    return artist;
};

double Album::getPrice() const{
    return price;
};

int Album::getCopies() const {
    return copies;
};

void Album::purchaseAlbum(){
    copies-=1;
    totalAlbums-=1;
    totalSales+=price;

}

int Album::getTotalAlbums(){
    return totalAlbums;
}

double Album::getTotalSales(){
    return totalSales;

}
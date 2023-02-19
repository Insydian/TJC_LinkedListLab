#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;
struct Song
{
    string composerName; 
    string songName; 
    
    Song() {};
    Song(string composerName, string songName)
        :composerName(composerName),
        songName(songName)
    {
    }
    ~Song(){
        composerName.erase();
        songName.erase();

    }
    bool operator==(const Song aSong)
    {
        if(this->composerName == aSong.composerName && this->songName == aSong.songName)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    bool operator!=(const Song aSong)
    {
        if(this->composerName == aSong.composerName && this->songName == aSong.songName)
        {
            return false;
        }
        else 
        {
            return true;
        }

    }

};
std::ostream& operator<<( std::ostream& os, const Song& song) {
    os << song.songName;
    return os;
}
Song randomSongGenerator()
{
    string firstName[]= {"John", "Ludwig", "Hildegard" , "George", "Antonio", "Claude"};
    string lastName[] = {"Bach" , "Mozart", "Beethoven", "Monteverdi", "Handel", "Vivaldi"};

    string songAdjectives[] = {"Mystery" , "Fire of my", "Soul", "Depths", "Without", "Remember"};
    string songNoun[] = {"Power", "Friend", "Midnight", "Yesterday", "Story", "Blues"};

    // make the song 
    string fullName = firstName[ std::rand()/((RAND_MAX + 1u)/6)] + " " + lastName[std::rand()/((RAND_MAX + 1u)/6)];
    string songName = songAdjectives[std::rand()/((RAND_MAX + 1u)/6)] + " " + songNoun[std::rand()/((RAND_MAX + 1u)/6)]; 
    Song randomSong(fullName , songName);


    return randomSong;

}

int main ()
{
    LinkedList<Song> SongList;
    for(int i = 0; i < 100; ++i)
    {
        Song aSong = randomSongGenerator();
        SongList.insertFirst(aSong);
    }
    for(int i = 0; i < SongList.length(); ++i)
    {
        std::cout << "Song " << i + 1 << " : " << endl;
        std::cout << SongList.getNode(i)->info.songName << std::endl;
        std::cout << SongList.getNode(i)->info.composerName << std::endl;
    }
    Song Radioactive("Imagine Dragons", "Radioactive");
    Song N95("Kendrick Lamar" , "N95"); 
    SongList.insertAfter(SongList.getNode(SongList.length()-1), Radioactive);
    SongList.insertAfter(SongList.getNode(SongList.length()/2), N95); 
    cout << "-------------------------------------------------------------" << endl;
    cout << "Add Radioactive and N95 at positions 101 and 50 respectively." << endl;
    cout << "Searching for songs" << endl;
    if(SongList.search(Radioactive))
    {
        cout << "found " << Radioactive.songName << endl;
    }
    else 
    {
        cout << "didn't find it" << endl;
    }
    if(SongList.search(N95))
    {
        cout << "found " << N95.songName << endl;
    }
    else 
    {
        cout << "didn't find it!" << endl;
    }
    SongList.deleteNodeWithInfo(N95);
    cout << "deleted the song N95" << endl;
    return 0;
}

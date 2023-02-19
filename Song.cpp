#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <string>
#include <forward_list>
#include "LinkedList.h"
using namespace std;
struct Song
{
    string composerName; 
    string songName; 
    ;
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
//    Song(Song&& aSong)
//    {
//        this->songName = aSong.songName;
//        this->composerName = aSong.composerName;
//
//
//    }
};
Song randomSongGenerator()
{
    string firstName[]= {"John", "Ludwig", "Hildegard" , "George", "Antonio", "Claude"};
    string lastName[] = {"Bach" , "Mozart", "Beethoven", "Monteverdi", "Handel", "Vivaldi"};

    string songAdjectives[] = {"Mystery" , "Fire of my", "Soul", "Depths", "Without", "Remember"};
    string songNoun[] = {"Power", "Friend", "Midnight", "Yesterday", "Story", "Blues"};

    srand(0);
    // make the song 
    string fullName = firstName[ std::rand()/((RAND_MAX + 1u)/6)] + " " + lastName[std::rand()/((RAND_MAX + 1u)/6)];
    string songName = songAdjectives[std::rand()/((RAND_MAX + 1u)/6)] + " " + songNoun[std::rand()/((RAND_MAX + 1u)/6)]; 
    Song randomSong(fullName , songName);


    return randomSong;

}

int main ()
{
    std::forward_list<Song> songList;
    for(int i = 0; i < 20; ++i)
    {
        songList.push_front(randomSongGenerator());
    }
    for (std::forward_list<Song>::iterator it = songList.begin(); it != songList.end(); ++it)
    {
        std::cout << it -> songName << endl;
    }
    LinkedList<Song> SongList;
    for(int i = 0; i < 20; ++i)
    {
        Song aSong = randomSongGenerator();
        SongList.insertFirst(aSong);
      //  for(int j = 0; j < SongList.length(); ++j)
      //  {
      //      std::cout << "List as of " << j << "is: " << SongList.getNode(j)->info.songName << std::endl;
      //  }
    }
    cout << "-------------------------------------------------------------" << endl;
    for(int i = 0; i < SongList.length(); ++i)
    {
        std::cout << SongList.getNode(i)->info.songName << std::endl;
    }
    return 0;
}

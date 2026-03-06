#include "MusTrack.h"
#include "Queue.h"

int main() {
    Queue<MusTrack> playlist;

    playlist.enqueue(MusTrack("Song 1", "Author 1", "3:20"));
    playlist.enqueue(MusTrack("Song 2", "Author 2", "4:10"));
    playlist.enqueue(MusTrack("Song 3", "Author 3", "2:50"));
    playlist.enqueue(MusTrack("Song 4", "Author 4", "5:00"));
    playlist.enqueue(MusTrack("Song 5", "Author 5", "3:40"));

    std::cout << "Starting playlist:" << std::endl;

    for (int i = 0; i < 10; ++i) 
        MusTrack track = playlist.dequeue();
        track.print();
        playlist.enqueue(track);
    }

    return 0;
}
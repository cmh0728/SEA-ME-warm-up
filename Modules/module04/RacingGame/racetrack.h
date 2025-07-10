#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
public:
    RaceTrack(int size, int finishLine);
    int finishLine() const;

private:
    int m_size; //track size
    int m_finishLine; //finish line information
};

#endif // RACETRACK_H

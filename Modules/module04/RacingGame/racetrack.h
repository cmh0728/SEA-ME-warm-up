#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack {
public:
    RaceTrack(int size, int finishLine);
    int finishLine() const;

private:
    int m_size;
    int m_finishLine;
};

#endif // RACETRACK_H

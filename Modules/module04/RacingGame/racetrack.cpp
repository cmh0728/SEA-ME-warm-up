#include "racetrack.h"

RaceTrack::RaceTrack(int size, int finishLine)
    : m_size(size), m_finishLine(finishLine) {}

int RaceTrack::finishLine() const { return m_finishLine; }

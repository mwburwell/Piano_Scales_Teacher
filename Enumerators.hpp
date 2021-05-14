#pragma once
#include <map>
#include <string>

// notes enum
enum class Note {C,DFlat,D,EFlat,E,F,GFlat,G,AFlat,A,BFlat,B};
std::map<Note,std::string> noteToString {
    {Note::C, "C"},
    {Note::DFlat, "D-flat"},
    {Note::D, "D"},
    {Note::EFlat, "E-flat"},
    {Note::E, "E"},
    {Note::F, "F"},
    {Note::GFlat, "G-flat"},
    {Note::G, "G"},
    {Note::AFlat, "A-flat"},
    {Note::A, "A"},
    {Note::BFlat, "B-flat"},
    {Note::B, "B"}
};

// modes 
enum class ScaleType {IONIAN, DORIAN,PHRYGIAN,LYDIAN,MIXOLYDIAN,AEOLIAN,LOCRIAN};
std::map<ScaleType, std::string> scaleTypeNames {
    {ScaleType::IONIAN, "Major"},
    {ScaleType::AEOLIAN, "Minor"}
};


enum class Chords {TRIAD, SEVENTH, SUS2, SUS4};
std::map<Chords, std::string> chordTypeName {
    {Chords::TRIAD, "Triad"},
    {Chords::SEVENTH, "Seventh"},
    {Chords::SUS2, "Sus2"},
    {Chords::SUS4, "Sus4"}
};

enum class NoteFromRoot {FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH, EIGHTH};
std::map<NoteFromRoot, std::string> majorNoteFromRoot {
    {NoteFromRoot::FIRST, "I"},
    {NoteFromRoot::SECOND, "II"},
    {NoteFromRoot::THIRD, "III"},
    {NoteFromRoot::FOURTH, "IV"},
    {NoteFromRoot::FIFTH, "V"},
    {NoteFromRoot::SIXTH, "VI"},
    {NoteFromRoot::SEVENTH, "VII"},
    {NoteFromRoot::EIGHTH, "VIII"},
};
std::map<NoteFromRoot, std::string> minorNoteFromRoot {
    {NoteFromRoot::FIRST, "i"},
    {NoteFromRoot::SECOND, "ii"},
    {NoteFromRoot::THIRD, "iii"},
    {NoteFromRoot::FOURTH, "iv"},
    {NoteFromRoot::FIFTH, "v"},
    {NoteFromRoot::SIXTH, "vi"},
    {NoteFromRoot::SEVENTH, "vii"},
    {NoteFromRoot::EIGHTH, "viii"},
};

enum class Sharps {CSharp,DSharp,ESharp,FSharp,GSharp,ASharp,BSharp};

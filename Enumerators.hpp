#pragma once
#include <map>
#include <string>

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
enum class Sharps {CSharp,DSharp,ESharp,FSharp,GSharp,ASharp,BSharp};

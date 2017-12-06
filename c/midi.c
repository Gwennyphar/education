#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[])
{
int Lautstaerke=100;
int Ton=60;//C1
int Kanal=1;
int Instrument=1;//Klavier
long StartMidi;
long EndMidi;
long Sound;
int Tonlaenge=1;//(in Sekunden)
int Treibernummer=0;

HMIDIOUT hMidiOut;

midiOutOpen(&hMidiOut, Treibernummer, 0, 0, 0);

for(;Ton<73;Ton++)
{
StartMidi=(65536 * Lautstaerke) + (256 * Ton) + Kanal+143;
EndMidi=(65536 * Lautstaerke) + (256 * Ton) + Kanal+127;
Sound=(256 * Instrument) + Kanal+191;

midiOutShortMsg(hMidiOut, Sound);
midiOutShortMsg(hMidiOut, StartMidi);
Sleep(Tonlaenge*1000);

midiOutShortMsg(hMidiOut, EndMidi); // MIDI aufräumen
}
midiOutReset(hMidiOut);
midiOutClose(hMidiOut);

system("PAUSE"); 
return 0; 
}

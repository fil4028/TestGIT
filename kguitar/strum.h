// STRUM.H - library of various strumming patterns

#include "strumlib.h"

// The library itself.

// First field of record should be an array with bitmasked strum
// pattern. Please add up TR and BS macros with "+" operator to get
// the proper results. See the examples below.

// TR macros reference strings from highest to lowest, i.e. TR1
// references the top tab line with standard 6-string guitar.

// BS macros reference strings vice versa, from lowest to highest,
// i.e. BS1 references the bottom tab line with guitar.

// Second field should be with durations of notes of corresponding
// bitmasked patterns in the first array, all in MIDI note length
// notation.

// Third field should be a human-readable name of given strumming
// scheme.

// Fourth field should describe the pattern a little, including it's
// pros and cons, complexity, what songs it sounds best in and
// possibly a well-known song where it is used or originated from.

strummer lib_strum[] = {
	{ {},
	  { 1 },
	  "Chord",
	  "Plain single chord, all notes sound at the same time." },
	{ { BS1, TR3, TR2, TR1, TR2, TR3 },
	  { 60,  60,  60,  60,  60,  60, 0 },
	  "6/8 Standard Arpegio",
	  "Classic arpegio, played in 6/8. Makes very good accompaniment "
	  "for slow, lyric songs. Used in the raw form (playing open "
	  "strings) by Metallica in the song \"Nothing Else Matters\"" },
	{ { BS1, TR3, TR2 + TR1, TR3 },
	  { 120, 120, 120,       120, 0 },
	  "4/4 Short Arpegio",
	  "Shortened variation of classic arpegio, with chord-like two "
	  "simultaneous string pick in the middle. A cross between classic "
	  "arpegio and bass pick technique." },
	{ { BS1, TR3, TR2, TR3, TR1, TR3, TR2, TR3 },
	  { 60,  60,  60,  60,  60,  60,  60,  60, 0 },
	  "8/8 Arpegio 1",
	  "Pretty complex arpegio that makes dynamic progressing and "
	  "continuous rhythm line. Fits best in medium tempo upbeat songs." },
	{ { BS1, TR3, TR2, TR3, TR1, TR2, TR3, TR2 },
	  { 60,  60,  60,  60,  60,  60,  60,  60, 0 },
	  "8/8 Arpegio 2",
	  "Variantion of previous arpegio, can spice up sound if used "
	  "several times with previous rhythm." },
	{ { BS1, TR4, TR3, TR2, TR1, TR2, TR3 },
	  { 60,  30,  30,  60,  60,  60,  60, 0 },
	  "3/4 Smooth Arpegio With Return",
	  "Smooth accelerating and decelarating arpegio. Played mostly "
	  "with a pick, strumming relatively slow through the strings. "
	  "Well-known from a song \"House of the Rising Sun\", performed "
	  "by Animals and many others." },
	{ { BS1, BS2, BS3, TR1, TR2, TR3 },
	  { 120, 60,  60,  60,  60,  120, 0 },
	  "4/4 Rock Ballad Arpegio 1",
	  "Most famous rock arpegio. If played in a correct way, could make "
	  "a smooth continuous rhythm, good for verses. One of the most "
	  "well-known songs that uses such arpegio is \"Don\'t Cry\" by "
	  "Guns\'n\'Roses."	},
	{ { BS1, BS2, BS3, TR1, TR4, TR2, TR4 },
	  { 60,  60,  60,  120, 60,  60,  60, 0 },
	  "4/4 Rock Ballad Arpegio 2",
	  "Smooth rock ballad arpegio. Picking pattern could seem a bit "
	  "random-like, though the whole arpegio makes a pretty smooth "
	  "rhythm. Good for slow and lyric ballads. Performed by Smokie "
	  "in their song \"Living Next Door to Alice\"" },
	{ { BS1, TR1, TR2, TR3, TR1, TR2, TR3, TR1 },
	  { 60,  60,  60,  60,  60,  60,  60,  60, 0 },
	  "4/4 Rock Ballad Arpegio 3",
	  "Weird, but simple combination of classic arpegios, makes a "
	  "good continuous rock lyric arpegio, with a bit of spanish "
	  "feel. Used in the song of Scorpions \"Holiday\"" },
	{ { BS1, TR1 + TR2 + TR3, BS2, TR1 + TR2 + TR3 },
	  { 120, 120,             120, 120, 0 },
	  "4/4 Normal Bass Pick",
	  "Classic bass pick technique with alteration. Played in 2 steps: "
	  "at the first step some sort of bass note is picked and at the "
	  "second step the bunch of trebles sounds. Very popular thing for "
	  "lyric songs on acoustic (especially 7-string) guitar." },
	{ { BS1, TR1 + TR2 + TR3, TR1 + TR2 + TR3 },
	  { 120, 120,             120, 0 },
	  "3/4 Waltz Bass Pick",
	  "Waltz style bass pick. Makes a perfect dance rhythm - played on "
	  "3/4, with the first beat accented by bass note. Could be used in "
	  "classic guitar playing experience, for example, in orchestra." },
	{ { BS1, TR1 + TR2 + TR3, BS2, TR1 + TR2 + TR3 },
	  { 180, 60,              180, 60, 0 },
	  "4/4 Deep Bass Pick",
	  "Normal bass pick with a shuffled, bluesey feel, made by delaying "
	  "bass notes by an extra 1/8. A good simple rhythm for blues and "
	  "folk songs." },

	{ {}, { 0 }, "", "" }
};
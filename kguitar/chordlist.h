#ifndef CHORDLIST_H
#define CHORDLIST_H

#include <q3listbox.h>
#include "global.h"

#include "chordlistitem.h"

/**
 * Special QListBox that holds ChordListItem objects and keeps them
 * sorted.
 */
class ChordList: public Q3ListBox {
	Q_OBJECT
public:
	ChordList(QWidget *parent=0, const char *name=0);
	ChordListItem* currentItemPointer();
	void inSort(ChordListItem *it);
};

#endif

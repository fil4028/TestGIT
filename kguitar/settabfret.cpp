#include "settabfret.h"

// External files with tuning library
#include "tunings.h"
#include "radiustuner.h"

#include <klocale.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlabel.h>
//Added by qt3to4:
#include <QResizeEvent>

// Numbers of instruments that are selected by default with selection
// of new number of strings

int defaultByString[MAX_STRINGS] =
	{ 0,
	  0,
	  0,
	  11,    // 4 string bass guitar
	  13,    // 5 string bass guitar
	  1,     // 6 string guitar
	  8,     // 7 string guitar
	  10,    // 8 string brahms guitar
	  0,
	  0,
	  0,
	  0 };

SetTabFret::SetTabFret(QWidget *parent, const char *name)
	: QWidget(parent, name)
{
    // Controls

    lib = new QComboBox(FALSE, this);
    connect(lib, SIGNAL(highlighted(int)), SLOT(setLibTuning(int)));

    for (int i = 0; lib_tuning[i].strings; i++)
		lib->insertItem(i18n(lib_tuning[i].name));

    QLabel *lib_l = new QLabel(i18n("Tuning:"), this);
    lib_l->setGeometry(10, 20, 80, 20);

    st = new QSpinBox(1, MAX_STRINGS, 1, this);
    connect(st, SIGNAL(valueChanged(int)), SLOT(stringChanged(int)));
    connect(st, SIGNAL(valueChanged(int)), SLOT(tuneChanged()));
    st->setGeometry(90, 50, 40, 20);

    QLabel *st_l = new QLabel(i18n("Strings:"), this);
    st_l->setGeometry(10, 50, 50, 20);

    fr = new QSpinBox(1, MAX_FRETS, 1, this);
    fr->setGeometry(190, 50, 40, 20);

    QLabel *fr_l = new QLabel(i18n("Frets:"), this);
    fr_l->setGeometry(140, 50, 50, 20);

    // Tuners

    for (int i = 0; i < MAX_STRINGS; i++) {
		tuner[i] = new RadiusTuner(this);
		connect(tuner[i], SIGNAL(valueChanged(int)), SLOT(tuneChanged()));
    }
    oldst = MAX_STRINGS;
}

void SetTabFret::setLibTuning(int n)
{
    if (n) {
		st->setValue(lib_tuning[n].strings);
		for (int i = 0; i < lib_tuning[n].strings; i++)
			tuner[i]->setValue(lib_tuning[n].shift[i]);
    } else {
		tuneChanged();
    }
}

void SetTabFret::stringChanged(int n)
{
    if (oldst == n)
		return;

	if (defaultByString[n - 1] != 0)
		for (int i = 0; i < n; i++)
			tuner[i]->setValue(lib_tuning[defaultByString[n - 1]].shift[i]);

    if (oldst < n) {       // Need to add
		for (int i = oldst; i < n; i++)
			tuner[i]->show();
    } else {             // Need to delete
		for (int i = n; i < oldst; i++)
			tuner[i]->hide();
    }
    oldst = n;

    setMinimumSize(QMAX(330, 20 + RADTUNER_W * n), 90+RADTUNER_H);
    reposTuners();
}

void SetTabFret::tuneChanged()
{
    int found = 0;

    for (int i = 1; lib_tuning[i].strings; i++) {
		if (lib_tuning[i].strings != st->value())
			continue;
		bool ok = TRUE;
		for (int j = 0; j < lib_tuning[i].strings; j++)
			if (tuner[j]->value() != lib_tuning[i].shift[j]) {
				ok = FALSE;
				break;
			}
		if (ok) {
			found = i;
			break;
		}
    }

    lib->setCurrentItem(found);
}

void SetTabFret::resizeEvent(QResizeEvent *)
{
    lib->setGeometry(90, 20, width() - 110, 20);
    reposTuners();
}

void SetTabFret::reposTuners()
{
    int s = st->value();                // Current number of tuners

    int tw = (width() - 20) / s;        // Width of one tuner
    int th = height() - 90;             // Height of one tuner

    for (int i = 0; i < s; i++)
		tuner[i]->setGeometry(10 + i * tw, 80, tw, th);
}

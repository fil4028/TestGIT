#include "settabfret.h"

// External files with tuning library
#include "tunings.h"
#include "radiustuner.h"

#include <kapp.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qlabel.h>

SetTabFret::SetTabFret(QWidget *parent=0, const char *name=0):
    QGroupBox(i18n("Fret tabulature"),parent,name)
{
    // Controls

    lib = new QComboBox(FALSE,this);
    connect(lib,SIGNAL(highlighted(int)),SLOT(setLibTuning(int)));

    for (int i=0;lib_tuning[i].strings;i++)
	lib->insertItem(lib_tuning[i].name);

    QLabel *lib_l = new QLabel(i18n("Tuning:"),this);
    lib_l->setGeometry(10,20,50,20);

    st = new QSpinBox(1,MAX_STRINGS,1,this);
    connect(st,SIGNAL(valueChanged(int)),SLOT(stringChanged(int)));

    QLabel *st_l = new QLabel(i18n("Strings:"),this);
    st_l->setGeometry(10,50,50,20);

    fr = new QSpinBox(1,MAX_FRETS,1,this);

    QLabel *fr_l = new QLabel(i18n("Frets:"),this);
    fr_l->setGeometry(140,50,50,20);

    // Tuners

    for (int i=0;i<MAX_STRINGS;i++)
	tuner[i] = new RadiusTuner(this);
    oldst=MAX_STRINGS;
}

void SetTabFret::setLibTuning(int n)
{
    st->setValue(lib_tuning[n].strings);
    for (int i=0;i<lib_tuning[n].strings;i++)
	tuner[i]->setValue(lib_tuning[n].shift[i]);
}

void SetTabFret::stringChanged(int n)
{
    if (oldst==n)
	return;

    if (oldst<n) {       // Need to add
	for (int i=oldst;i<n;i++)
	    tuner[i]->show();
    } else {             // Need to delete
	for (int i=n;i<oldst;i++)
	    tuner[i]->hide();
    }
    oldst=n;

    // GREYFIX: Maximum operation. Unportable?
    setMinimumSize(330 >? 20+RADTUNER_W*n,90+RADTUNER_H);
    resize(width(),height());
}

void SetTabFret::resizeEvent(QResizeEvent *e)
{
    lib->setGeometry(80,20,width()-110,20);
    st->setGeometry(80,50,40,20);
    fr->setGeometry(190,50,40,20);

    int s = st->value();                // Current number of tuners

    int tw = (width()-20)/s;            // Width of one tuner
    int th = height()-90;               // Height of one tuner

    for (int i=0;i<s;i++)
	tuner[i]->setGeometry(10+i*tw,80,tw,th);
}

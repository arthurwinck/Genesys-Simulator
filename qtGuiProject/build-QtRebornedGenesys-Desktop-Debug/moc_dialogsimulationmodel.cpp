/****************************************************************************
 ** Meta object code from reading C++ file 'dialogsimulationmodel.h'
 **
 ** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
 **
 ** WARNING! All changes made in this file will be lost!
 *****************************************************************************/

#include "../QtRebornedGenesys/dialogsimulationmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsimulationmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogSimulationModel_t {
	QByteArrayData data[8];
	char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSimulationModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSimulationModel_t qt_meta_stringdata_DialogSimulationModel = {
	{
		QT_MOC_LITERAL(0, 0, 21), // "DialogSimulationModel"
		QT_MOC_LITERAL(1, 22, 10), // "_on_reject"
		QT_MOC_LITERAL(2, 33, 0), // ""
		QT_MOC_LITERAL(3, 34, 36), // "on_horizontalSliderZoom_value..."
		QT_MOC_LITERAL(4, 71, 5), // "value"
		QT_MOC_LITERAL(5, 77, 33), // "_on_graphicalmodelScene_mouse..."
		QT_MOC_LITERAL(6, 111, 12), // "QMouseEvent*"
		QT_MOC_LITERAL(7, 124, 5) // "event"

	},
	"DialogSimulationModel\0_on_reject\0\0"
	"on_horizontalSliderZoom_valueChanged\0"
	"value\0_on_graphicalmodelScene_mousemove\0"
	"QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSimulationModel[] = {

	// content:
	8, // revision
	0, // classname
	0, 0, // classinfo
	3, 14, // methods
	0, 0, // properties
	0, 0, // enums/sets
	0, 0, // constructors
	0, // flags
	0, // signalCount

	// slots: name, argc, parameters, tag, flags
	1, 0, 29, 2, 0x08 /* Private */,
	3, 1, 30, 2, 0x08 /* Private */,
	5, 1, 33, 2, 0x08 /* Private */,

	// slots: parameters
	QMetaType::Void,
	QMetaType::Void, QMetaType::Int, 4,
	QMetaType::Void, 0x80000000 | 6, 7,

	0 // eod
};

void DialogSimulationModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a) {
	if (_c == QMetaObject::InvokeMetaMethod) {
		auto *_t = static_cast<DialogSimulationModel *> (_o);
		Q_UNUSED(_t)
		switch (_id) {
			case 0: _t->_on_reject();
				break;
			case 1: _t->on_horizontalSliderZoom_valueChanged((*reinterpret_cast<int(*)> (_a[1])));
				break;
			case 2: _t->_on_graphicalmodelScene_mousemove((*reinterpret_cast<QMouseEvent * (*)> (_a[1])));
				break;
			default:;
		}
	}
}

QT_INIT_METAOBJECT const QMetaObject DialogSimulationModel::staticMetaObject = {
	{
		&QDialog::staticMetaObject,
		qt_meta_stringdata_DialogSimulationModel.data,
		qt_meta_data_DialogSimulationModel,
		qt_static_metacall,
		nullptr,
		nullptr
	}
};

const QMetaObject *DialogSimulationModel::metaObject() const {
	return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSimulationModel::qt_metacast(const char *_clname) {
	if (!_clname) return nullptr;
	if (!strcmp(_clname, qt_meta_stringdata_DialogSimulationModel.stringdata0))
		return static_cast<void*> (this);
	return QDialog::qt_metacast(_clname);
}

int DialogSimulationModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a) {
	_id = QDialog::qt_metacall(_c, _id, _a);
	if (_id < 0)
		return _id;
	if (_c == QMetaObject::InvokeMetaMethod) {
		if (_id < 3)
			qt_static_metacall(this, _c, _id, _a);
		_id -= 3;
	} else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
		if (_id < 3)
			* reinterpret_cast<int*> (_a[0]) = -1;
		_id -= 3;
	}
	return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
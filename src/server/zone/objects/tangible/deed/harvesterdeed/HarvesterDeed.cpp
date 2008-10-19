/*
 *	server/zone/objects/tangible/deed/harvesterdeed/HarvesterDeed.cpp generated by engine3 IDL compiler 0.55
 */

#include "HarvesterDeed.h"

#include "HarvesterDeedImplementation.h"

#include "../DeedObject.h"

#include "../../TangibleObject.h"

#include "../../../../packets.h"

#include "../../../player/Player.h"

#include "../../../creature/CreatureObject.h"

/*
 *	HarvesterDeedStub
 */

HarvesterDeed::HarvesterDeed(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new HarvesterDeedImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

HarvesterDeed::HarvesterDeed(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new HarvesterDeedImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

HarvesterDeed::HarvesterDeed(DummyConstructorParameter* param) : DeedObject(param) {
}

HarvesterDeed::~HarvesterDeed() {
}

void HarvesterDeed::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->parseItemAttributes();
}

void HarvesterDeed::setSurplusMaintenance(int maint) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(maint);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->setSurplusMaintenance(maint);
}

void HarvesterDeed::setMaintenanceRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->setMaintenanceRate(rate);
}

void HarvesterDeed::setSurplusPower(int pow) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(pow);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->setSurplusPower(pow);
}

void HarvesterDeed::setExtractionRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->setExtractionRate(rate);
}

void HarvesterDeed::setHopperSize(float size) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addFloatParameter(size);

		method.executeWithVoidReturn();
	} else
		((HarvesterDeedImplementation*) _impl)->setHopperSize(size);
}

int HarvesterDeed::getSurplusMaintenance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((HarvesterDeedImplementation*) _impl)->getSurplusMaintenance();
}

float HarvesterDeed::getMaintenanceRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithFloatReturn();
	} else
		return ((HarvesterDeedImplementation*) _impl)->getMaintenanceRate();
}

int HarvesterDeed::getSurplusPower() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((HarvesterDeedImplementation*) _impl)->getSurplusPower();
}

float HarvesterDeed::getExtractionRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithFloatReturn();
	} else
		return ((HarvesterDeedImplementation*) _impl)->getExtractionRate();
}

float HarvesterDeed::getHopperSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithFloatReturn();
	} else
		return ((HarvesterDeedImplementation*) _impl)->getHopperSize();
}

/*
 *	HarvesterDeedAdapter
 */

HarvesterDeedAdapter::HarvesterDeedAdapter(HarvesterDeedImplementation* obj) : DeedObjectAdapter(obj) {
}

Packet* HarvesterDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		parseItemAttributes();
		break;
	case 7:
		setSurplusMaintenance(inv->getSignedIntParameter());
		break;
	case 8:
		setMaintenanceRate(inv->getFloatParameter());
		break;
	case 9:
		setSurplusPower(inv->getSignedIntParameter());
		break;
	case 10:
		setExtractionRate(inv->getFloatParameter());
		break;
	case 11:
		setHopperSize(inv->getFloatParameter());
		break;
	case 12:
		resp->insertSignedInt(getSurplusMaintenance());
		break;
	case 13:
		resp->insertFloat(getMaintenanceRate());
		break;
	case 14:
		resp->insertSignedInt(getSurplusPower());
		break;
	case 15:
		resp->insertFloat(getExtractionRate());
		break;
	case 16:
		resp->insertFloat(getHopperSize());
		break;
	default:
		return NULL;
	}

	return resp;
}

void HarvesterDeedAdapter::parseItemAttributes() {
	return ((HarvesterDeedImplementation*) impl)->parseItemAttributes();
}

void HarvesterDeedAdapter::setSurplusMaintenance(int maint) {
	return ((HarvesterDeedImplementation*) impl)->setSurplusMaintenance(maint);
}

void HarvesterDeedAdapter::setMaintenanceRate(float rate) {
	return ((HarvesterDeedImplementation*) impl)->setMaintenanceRate(rate);
}

void HarvesterDeedAdapter::setSurplusPower(int pow) {
	return ((HarvesterDeedImplementation*) impl)->setSurplusPower(pow);
}

void HarvesterDeedAdapter::setExtractionRate(float rate) {
	return ((HarvesterDeedImplementation*) impl)->setExtractionRate(rate);
}

void HarvesterDeedAdapter::setHopperSize(float size) {
	return ((HarvesterDeedImplementation*) impl)->setHopperSize(size);
}

int HarvesterDeedAdapter::getSurplusMaintenance() {
	return ((HarvesterDeedImplementation*) impl)->getSurplusMaintenance();
}

float HarvesterDeedAdapter::getMaintenanceRate() {
	return ((HarvesterDeedImplementation*) impl)->getMaintenanceRate();
}

int HarvesterDeedAdapter::getSurplusPower() {
	return ((HarvesterDeedImplementation*) impl)->getSurplusPower();
}

float HarvesterDeedAdapter::getExtractionRate() {
	return ((HarvesterDeedImplementation*) impl)->getExtractionRate();
}

float HarvesterDeedAdapter::getHopperSize() {
	return ((HarvesterDeedImplementation*) impl)->getHopperSize();
}

/*
 *	HarvesterDeedHelper
 */

HarvesterDeedHelper* HarvesterDeedHelper::staticInitializer = HarvesterDeedHelper::instance();

HarvesterDeedHelper::HarvesterDeedHelper() {
	className = "HarvesterDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void HarvesterDeedHelper::finalizeHelper() {
	HarvesterDeedHelper::finalize();
}

DistributedObject* HarvesterDeedHelper::instantiateObject() {
	return new HarvesterDeed(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* HarvesterDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new HarvesterDeedAdapter((HarvesterDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	HarvesterDeedServant
 */

HarvesterDeedServant::HarvesterDeedServant(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(creature, tempCRC, n, tempn, tp) {
	_classHelper = HarvesterDeedHelper::instance();
}

HarvesterDeedServant::HarvesterDeedServant(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(oid, tempCRC, n, tempn, tp) {
	_classHelper = HarvesterDeedHelper::instance();
}

HarvesterDeedServant::~HarvesterDeedServant() {
}

void HarvesterDeedServant::_setStub(DistributedObjectStub* stub) {
	_this = (HarvesterDeed*) stub;
	DeedObjectServant::_setStub(stub);
}

DistributedObjectStub* HarvesterDeedServant::_getStub() {
	return _this;
}


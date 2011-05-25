/*
 *	server/zone/objects/creature/AiObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "AiObserver.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/objects/scene/SceneObject.h"


// Imported class dependencies

#include "engine/util/Observer.h"

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/creature/PatrolPointsVector.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/AiObserver.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/objects/scene/WorldCoordinates.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/managers/creature/CreatureTemplate.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/creature/PatrolPoint.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/creature/events/AiThinkEvent.h"

#include "server/zone/objects/creature/events/DespawnCreatureOnPlayerDissappear.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/creature/events/AiMoveEvent.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/creature/events/AiWaitEvent.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/creature/events/AiAwarenessEvent.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	AiObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6};

AiObserver::AiObserver(AiAgent* agent) : Observer(DummyConstructorParameter::instance()) {
	AiObserverImplementation* _implementation = new AiObserverImplementation(agent);
	_impl = _implementation;
	_impl->_setStub(this);
}

AiObserver::AiObserver(DummyConstructorParameter* param) : Observer(param) {
}

AiObserver::~AiObserver() {
}


int AiObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	AiObserverImplementation* _implementation = (AiObserverImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

DistributedObjectServant* AiObserver::_getImplementation() {

	_updated = true;
	return _impl;
}

void AiObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AiObserverImplementation
 */

AiObserverImplementation::AiObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


AiObserverImplementation::~AiObserverImplementation() {
}


void AiObserverImplementation::finalize() {
}

void AiObserverImplementation::_initializeImplementation() {
	_setClassHelper(AiObserverHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AiObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AiObserver*) stub;
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* AiObserverImplementation::_getStub() {
	return _this;
}

AiObserverImplementation::operator const AiObserver*() {
	return _this;
}

void AiObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AiObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AiObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AiObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AiObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AiObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AiObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AiObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("AiObserver");

}

void AiObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AiObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AiObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "aiAgent") {
		TypeInfo<ManagedReference<AiAgent* > >::parseFromBinaryStream(&aiAgent, stream);
		return true;
	}


	return false;
}

void AiObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AiObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AiObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "aiAgent";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<AiAgent* > >::toBinaryStream(&aiAgent, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ObserverImplementation::writeObjectMembers(stream);
}

AiObserverImplementation::AiObserverImplementation(AiAgent* agent) {
	_initializeImplementation();
	// server/zone/objects/creature/AiObserver.idl():  		aiAgent = agent;
	aiAgent = agent;
	// server/zone/objects/creature/AiObserver.idl():  		Logger.setLoggingName("AiObserver");
	Logger::setLoggingName("AiObserver");
}

int AiObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/creature/AiObserver.idl():  			return 0;
	if (aiAgent == NULL)	// server/zone/objects/creature/AiObserver.idl():  			return 0;
	return 0;

	else 	// server/zone/objects/creature/AiObserver.idl():  			return 0;
	if (eventType == ObserverEventType::SPECIALATTACK)	// server/zone/objects/creature/AiObserver.idl():  			return aiAgent.notifyAttack(observable);
	return aiAgent->notifyAttack(observable);

	else 	// server/zone/objects/creature/AiObserver.idl():  			return 0;
	if (eventType == ObserverEventType::CALLFORHELP)	// server/zone/objects/creature/AiObserver.idl():  			return aiAgent.notifyCallForHelp(observable, arg1);
	return aiAgent->notifyCallForHelp(observable, arg1);

	else 	// server/zone/objects/creature/AiObserver.idl():  			return 0;
	return 0;
}

/*
 *	AiObserverAdapter
 */

AiObserverAdapter::AiObserverAdapter(AiObserverImplementation* obj) : ObserverAdapter(obj) {
}

Packet* AiObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int AiObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((AiObserverImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	AiObserverHelper
 */

AiObserverHelper* AiObserverHelper::staticInitializer = AiObserverHelper::instance();

AiObserverHelper::AiObserverHelper() {
	className = "AiObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void AiObserverHelper::finalizeHelper() {
	AiObserverHelper::finalize();
}

DistributedObject* AiObserverHelper::instantiateObject() {
	return new AiObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* AiObserverHelper::instantiateServant() {
	return new AiObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AiObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AiObserverAdapter((AiObserverImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


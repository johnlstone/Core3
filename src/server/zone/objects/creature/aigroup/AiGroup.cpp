/*
 *	server/zone/objects/creature/aigroup/AiGroup.cpp generated by engine3 IDL compiler 0.60
 */

#include "AiGroup.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/managers/creature/StaticSpawnGroup.h"

#include "server/zone/managers/creature/DynamicSpawnGroup.h"

#include "server/zone/objects/creature/aigroup/AiGroupObserver.h"


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

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/aigroup/AiGroupObserver.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/AiObserver.h"

#include "server/zone/managers/creature/StaticSpawnGroup.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

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

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/creature/events/DespawnCreatureOnPlayerDissappear.h"

#include "server/zone/objects/creature/events/AiThinkEvent.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/creature/events/AiMoveEvent.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/creature/events/AiWaitEvent.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/creature/DynamicSpawnGroup.h"

#include "server/zone/objects/creature/events/AiAwarenessEvent.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	AiGroupStub
 */

enum {RPC_SETPATROLPOINTS__ = 6,RPC_SETPATROLPOINT__AIAGENT_,RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_,RPC_ISHERDGROUP__,RPC_ISPACKGROUP__,RPC_ISLAIRGROUP__};

AiGroup::AiGroup() : SceneObject(DummyConstructorParameter::instance()) {
	AiGroupImplementation* _implementation = new AiGroupImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

AiGroup::AiGroup(DummyConstructorParameter* param) : SceneObject(param) {
}

AiGroup::~AiGroup() {
}


void AiGroup::setPatrolPoints() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPATROLPOINTS__);

		method.executeWithVoidReturn();
	} else
		_implementation->setPatrolPoints();
}

void AiGroup::setPatrolPoint(AiAgent* member) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPATROLPOINT__AIAGENT_);
		method.addObjectParameter(member);

		method.executeWithVoidReturn();
	} else
		_implementation->setPatrolPoint(member);
}

void AiGroup::setup(StaticSpawnGroup* templ) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setup(templ);
}

void AiGroup::setup(DynamicSpawnGroup* templ) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setup(templ);
}

int AiGroup::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
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

bool AiGroup::isHerdGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISHERDGROUP__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isHerdGroup();
}

bool AiGroup::isPackGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISPACKGROUP__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPackGroup();
}

bool AiGroup::isLairGroup() {
	AiGroupImplementation* _implementation = (AiGroupImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISLAIRGROUP__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isLairGroup();
}

DistributedObjectServant* AiGroup::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void AiGroup::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<AiGroupImplementation*>(servant));
}

/*
 *	AiGroupImplementation
 */

AiGroupImplementation::AiGroupImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


AiGroupImplementation::~AiGroupImplementation() {
}


void AiGroupImplementation::finalize() {
}

void AiGroupImplementation::_initializeImplementation() {
	_setClassHelper(AiGroupHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AiGroupImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AiGroup*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AiGroupImplementation::_getStub() {
	return _this;
}

AiGroupImplementation::operator const AiGroup*() {
	return _this;
}

Object* AiGroupImplementation::clone() {
	return dynamic_cast<Object*>(new AiGroupImplementation(*this));
}


void AiGroupImplementation::lock(bool doLock) {
}

void AiGroupImplementation::lock(ManagedObject* obj) {
}

void AiGroupImplementation::rlock(bool doLock) {
}

void AiGroupImplementation::wlock(bool doLock) {
}

void AiGroupImplementation::wlock(ManagedObject* obj) {
}

void AiGroupImplementation::unlock(bool doLock) {
}

void AiGroupImplementation::runlock(bool doLock) {
}

void AiGroupImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("AiGroup");

}

void AiGroupImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AiGroupImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AiGroupImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SceneObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "leader") {
		TypeInfo<ManagedReference<SceneObject* > >::parseFromBinaryStream(&leader, stream);
		return true;
	}

	if (_name == "scouts") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&scouts, stream);
		return true;
	}

	if (_name == "scoutTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&scoutTemps, stream);
		return true;
	}

	if (_name == "protectors") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&protectors, stream);
		return true;
	}

	if (_name == "protectorTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&protectorTemps, stream);
		return true;
	}

	if (_name == "babies") {
		TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::parseFromBinaryStream(&babies, stream);
		return true;
	}

	if (_name == "babyTemps") {
		TypeInfo<Vector<String> >::parseFromBinaryStream(&babyTemps, stream);
		return true;
	}

	if (_name == "subgroups") {
		TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::parseFromBinaryStream(&subgroups, stream);
		return true;
	}

	if (_name == "observers") {
		TypeInfo<SortedVector<ManagedReference<AiGroupObserver* > > >::parseFromBinaryStream(&observers, stream);
		return true;
	}

	if (_name == "commandLevel") {
		TypeInfo<int >::parseFromBinaryStream(&commandLevel, stream);
		return true;
	}

	if (_name == "wanderRadius") {
		TypeInfo<float >::parseFromBinaryStream(&wanderRadius, stream);
		return true;
	}

	if (_name == "size") {
		TypeInfo<int >::parseFromBinaryStream(&size, stream);
		return true;
	}

	if (_name == "scoutWeight") {
		TypeInfo<float >::parseFromBinaryStream(&scoutWeight, stream);
		return true;
	}

	if (_name == "protectorWeight") {
		TypeInfo<float >::parseFromBinaryStream(&protectorWeight, stream);
		return true;
	}

	if (_name == "babyWeight") {
		TypeInfo<float >::parseFromBinaryStream(&babyWeight, stream);
		return true;
	}

	if (_name == "isStatic") {
		TypeInfo<bool >::parseFromBinaryStream(&isStatic, stream);
		return true;
	}


	return false;
}

void AiGroupImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AiGroupImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AiGroupImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "leader";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<SceneObject* > >::toBinaryStream(&leader, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scouts";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&scouts, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scoutTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&scoutTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectors";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&protectors, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectorTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&protectorTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babies";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiAgent* > > >::toBinaryStream(&babies, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babyTemps";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<Vector<String> >::toBinaryStream(&babyTemps, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "subgroups";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::toBinaryStream(&subgroups, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "observers";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<SortedVector<ManagedReference<AiGroupObserver* > > >::toBinaryStream(&observers, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "commandLevel";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&commandLevel, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "wanderRadius";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&wanderRadius, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "size";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&size, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "scoutWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&scoutWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "protectorWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&protectorWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "babyWeight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&babyWeight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "isStatic";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<bool >::toBinaryStream(&isStatic, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 16 + SceneObjectImplementation::writeObjectMembers(stream);
}

AiGroupImplementation::AiGroupImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		Logger.setLoggingName("AiGroup");
	Logger::setLoggingName("AiGroup");
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		commandLevel = 0;
	commandLevel = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		wanderRadius = 0;
	wanderRadius = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		size = 0;
	size = 0;
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		isStatic = true;
	isStatic = true;
}

bool AiGroupImplementation::isHerdGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		return false;
	return false;
}

bool AiGroupImplementation::isPackGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		return false;
	return false;
}

bool AiGroupImplementation::isLairGroup() {
	// server/zone/objects/creature/aigroup/AiGroup.idl():  		return false;
	return false;
}

/*
 *	AiGroupAdapter
 */

AiGroupAdapter::AiGroupAdapter(AiGroupImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* AiGroupAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_SETPATROLPOINTS__:
		setPatrolPoints();
		break;
	case RPC_SETPATROLPOINT__AIAGENT_:
		setPatrolPoint((AiAgent*) inv->getObjectParameter());
		break;
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case RPC_ISHERDGROUP__:
		resp->insertBoolean(isHerdGroup());
		break;
	case RPC_ISPACKGROUP__:
		resp->insertBoolean(isPackGroup());
		break;
	case RPC_ISLAIRGROUP__:
		resp->insertBoolean(isLairGroup());
		break;
	default:
		return NULL;
	}

	return resp;
}

void AiGroupAdapter::setPatrolPoints() {
	((AiGroupImplementation*) impl)->setPatrolPoints();
}

void AiGroupAdapter::setPatrolPoint(AiAgent* member) {
	((AiGroupImplementation*) impl)->setPatrolPoint(member);
}

int AiGroupAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((AiGroupImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

bool AiGroupAdapter::isHerdGroup() {
	return ((AiGroupImplementation*) impl)->isHerdGroup();
}

bool AiGroupAdapter::isPackGroup() {
	return ((AiGroupImplementation*) impl)->isPackGroup();
}

bool AiGroupAdapter::isLairGroup() {
	return ((AiGroupImplementation*) impl)->isLairGroup();
}

/*
 *	AiGroupHelper
 */

AiGroupHelper* AiGroupHelper::staticInitializer = AiGroupHelper::instance();

AiGroupHelper::AiGroupHelper() {
	className = "AiGroup";

	Core::getObjectBroker()->registerClass(className, this);
}

void AiGroupHelper::finalizeHelper() {
	AiGroupHelper::finalize();
}

DistributedObject* AiGroupHelper::instantiateObject() {
	return new AiGroup(DummyConstructorParameter::instance());
}

DistributedObjectServant* AiGroupHelper::instantiateServant() {
	return new AiGroupImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AiGroupHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AiGroupAdapter((AiGroupImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


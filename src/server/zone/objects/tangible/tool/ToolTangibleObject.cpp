/*
 *	server/zone/objects/tangible/tool/ToolTangibleObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "ToolTangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"


// Imported class dependencies

#include "engine/util/Observer.h"

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/group/GroupList.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	ToolTangibleObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6};

ToolTangibleObject::ToolTangibleObject() : TangibleObject(DummyConstructorParameter::instance()) {
	ToolTangibleObjectImplementation* _implementation = new ToolTangibleObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

ToolTangibleObject::ToolTangibleObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

ToolTangibleObject::~ToolTangibleObject() {
}


void ToolTangibleObject::initializeTransientMembers() {
	ToolTangibleObjectImplementation* _implementation = (ToolTangibleObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

DistributedObjectServant* ToolTangibleObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void ToolTangibleObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<ToolTangibleObjectImplementation*>(servant));
}

/*
 *	ToolTangibleObjectImplementation
 */

ToolTangibleObjectImplementation::ToolTangibleObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


ToolTangibleObjectImplementation::~ToolTangibleObjectImplementation() {
}


void ToolTangibleObjectImplementation::finalize() {
}

void ToolTangibleObjectImplementation::_initializeImplementation() {
	_setClassHelper(ToolTangibleObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ToolTangibleObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ToolTangibleObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ToolTangibleObjectImplementation::_getStub() {
	return _this;
}

ToolTangibleObjectImplementation::operator const ToolTangibleObject*() {
	return _this;
}

Object* ToolTangibleObjectImplementation::clone() {
	return dynamic_cast<Object*>(new ToolTangibleObjectImplementation(*this));
}


void ToolTangibleObjectImplementation::lock(bool doLock) {
}

void ToolTangibleObjectImplementation::lock(ManagedObject* obj) {
}

void ToolTangibleObjectImplementation::rlock(bool doLock) {
}

void ToolTangibleObjectImplementation::wlock(bool doLock) {
}

void ToolTangibleObjectImplementation::wlock(ManagedObject* obj) {
}

void ToolTangibleObjectImplementation::unlock(bool doLock) {
}

void ToolTangibleObjectImplementation::runlock(bool doLock) {
}

void ToolTangibleObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("ToolTangibleObject");

}

void ToolTangibleObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ToolTangibleObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ToolTangibleObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void ToolTangibleObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ToolTangibleObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ToolTangibleObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TangibleObjectImplementation::writeObjectMembers(stream);
}

ToolTangibleObjectImplementation::ToolTangibleObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/tool/ToolTangibleObject.idl():  		Logger.setLoggingName("ToolTangibleObject");
	Logger::setLoggingName("ToolTangibleObject");
}

void ToolTangibleObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/tool/ToolTangibleObject.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/tool/ToolTangibleObject.idl():  		Logger.setLoggingName("ToolTangibleObject");
	Logger::setLoggingName("ToolTangibleObject");
}

/*
 *	ToolTangibleObjectAdapter
 */

ToolTangibleObjectAdapter::ToolTangibleObjectAdapter(ToolTangibleObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ToolTangibleObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	default:
		return NULL;
	}

	return resp;
}

void ToolTangibleObjectAdapter::initializeTransientMembers() {
	((ToolTangibleObjectImplementation*) impl)->initializeTransientMembers();
}

/*
 *	ToolTangibleObjectHelper
 */

ToolTangibleObjectHelper* ToolTangibleObjectHelper::staticInitializer = ToolTangibleObjectHelper::instance();

ToolTangibleObjectHelper::ToolTangibleObjectHelper() {
	className = "ToolTangibleObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void ToolTangibleObjectHelper::finalizeHelper() {
	ToolTangibleObjectHelper::finalize();
}

DistributedObject* ToolTangibleObjectHelper::instantiateObject() {
	return new ToolTangibleObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* ToolTangibleObjectHelper::instantiateServant() {
	return new ToolTangibleObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ToolTangibleObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ToolTangibleObjectAdapter((ToolTangibleObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


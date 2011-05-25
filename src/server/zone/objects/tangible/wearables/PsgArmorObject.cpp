/*
 *	server/zone/objects/tangible/wearables/PsgArmorObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "PsgArmorObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


// Imported class dependencies

#include "engine/util/Observer.h"

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/professions/ProfessionManager.h"

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

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/lang/Time.h"

#include "server/zone/objects/tangible/attachment/Attachment.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/tangible/wearables/WearableSkillModMap.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	PsgArmorObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_ISPSGARMOROBJECT__,RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_};

PsgArmorObject::PsgArmorObject() : WearableObject(DummyConstructorParameter::instance()) {
	PsgArmorObjectImplementation* _implementation = new PsgArmorObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

PsgArmorObject::PsgArmorObject(DummyConstructorParameter* param) : WearableObject(param) {
}

PsgArmorObject::~PsgArmorObject() {
}


void PsgArmorObject::initializeTransientMembers() {
	PsgArmorObjectImplementation* _implementation = (PsgArmorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

bool PsgArmorObject::isPsgArmorObject() {
	PsgArmorObjectImplementation* _implementation = (PsgArmorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISPSGARMOROBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPsgArmorObject();
}

void PsgArmorObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	PsgArmorObjectImplementation* _implementation = (PsgArmorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

void PsgArmorObject::updateCraftingValues(ManufactureSchematic* schematic) {
	PsgArmorObjectImplementation* _implementation = (PsgArmorObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_);
		method.addObjectParameter(schematic);

		method.executeWithVoidReturn();
	} else
		_implementation->updateCraftingValues(schematic);
}

DistributedObjectServant* PsgArmorObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void PsgArmorObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<PsgArmorObjectImplementation*>(servant));
}

/*
 *	PsgArmorObjectImplementation
 */

PsgArmorObjectImplementation::PsgArmorObjectImplementation(DummyConstructorParameter* param) : WearableObjectImplementation(param) {
	_initializeImplementation();
}


PsgArmorObjectImplementation::~PsgArmorObjectImplementation() {
}


void PsgArmorObjectImplementation::finalize() {
}

void PsgArmorObjectImplementation::_initializeImplementation() {
	_setClassHelper(PsgArmorObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void PsgArmorObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PsgArmorObject*) stub;
	WearableObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PsgArmorObjectImplementation::_getStub() {
	return _this;
}

PsgArmorObjectImplementation::operator const PsgArmorObject*() {
	return _this;
}

Object* PsgArmorObjectImplementation::clone() {
	return dynamic_cast<Object*>(new PsgArmorObjectImplementation(*this));
}


void PsgArmorObjectImplementation::lock(bool doLock) {
}

void PsgArmorObjectImplementation::lock(ManagedObject* obj) {
}

void PsgArmorObjectImplementation::rlock(bool doLock) {
}

void PsgArmorObjectImplementation::wlock(bool doLock) {
}

void PsgArmorObjectImplementation::wlock(ManagedObject* obj) {
}

void PsgArmorObjectImplementation::unlock(bool doLock) {
}

void PsgArmorObjectImplementation::runlock(bool doLock) {
}

void PsgArmorObjectImplementation::_serializationHelperMethod() {
	WearableObjectImplementation::_serializationHelperMethod();

	_setClassName("PsgArmorObject");

}

void PsgArmorObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(PsgArmorObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool PsgArmorObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (WearableObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void PsgArmorObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = PsgArmorObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int PsgArmorObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + WearableObjectImplementation::writeObjectMembers(stream);
}

PsgArmorObjectImplementation::PsgArmorObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/wearables/PsgArmorObject.idl():  		Logger.setLoggingName("PsgArmorObject");
	Logger::setLoggingName("PsgArmorObject");
}

bool PsgArmorObjectImplementation::isPsgArmorObject() {
	// server/zone/objects/tangible/wearables/PsgArmorObject.idl():  		return true;
	return true;
}

/*
 *	PsgArmorObjectAdapter
 */

PsgArmorObjectAdapter::PsgArmorObjectAdapter(PsgArmorObjectImplementation* obj) : WearableObjectAdapter(obj) {
}

Packet* PsgArmorObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_ISPSGARMOROBJECT__:
		resp->insertBoolean(isPsgArmorObject());
		break;
	case RPC_UPDATECRAFTINGVALUES__MANUFACTURESCHEMATIC_:
		updateCraftingValues((ManufactureSchematic*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PsgArmorObjectAdapter::initializeTransientMembers() {
	((PsgArmorObjectImplementation*) impl)->initializeTransientMembers();
}

bool PsgArmorObjectAdapter::isPsgArmorObject() {
	return ((PsgArmorObjectImplementation*) impl)->isPsgArmorObject();
}

void PsgArmorObjectAdapter::updateCraftingValues(ManufactureSchematic* schematic) {
	((PsgArmorObjectImplementation*) impl)->updateCraftingValues(schematic);
}

/*
 *	PsgArmorObjectHelper
 */

PsgArmorObjectHelper* PsgArmorObjectHelper::staticInitializer = PsgArmorObjectHelper::instance();

PsgArmorObjectHelper::PsgArmorObjectHelper() {
	className = "PsgArmorObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void PsgArmorObjectHelper::finalizeHelper() {
	PsgArmorObjectHelper::finalize();
}

DistributedObject* PsgArmorObjectHelper::instantiateObject() {
	return new PsgArmorObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* PsgArmorObjectHelper::instantiateServant() {
	return new PsgArmorObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PsgArmorObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PsgArmorObjectAdapter((PsgArmorObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


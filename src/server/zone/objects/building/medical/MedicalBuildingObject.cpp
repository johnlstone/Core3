/*
 *	server/zone/objects/building/medical/MedicalBuildingObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "MedicalBuildingObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/cell/CellObject.h"


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

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

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

#include "server/zone/objects/structure/events/StructureMaintenanceTask.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/structure/StructurePermissionList.h"

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

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	MedicalBuildingObjectStub
 */

enum {RPC_ISMEDICALBUILDINGOBJECT__ = 6};

MedicalBuildingObject::MedicalBuildingObject() : BuildingObject(DummyConstructorParameter::instance()) {
	MedicalBuildingObjectImplementation* _implementation = new MedicalBuildingObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

MedicalBuildingObject::MedicalBuildingObject(DummyConstructorParameter* param) : BuildingObject(param) {
}

MedicalBuildingObject::~MedicalBuildingObject() {
}


bool MedicalBuildingObject::isMedicalBuildingObject() {
	MedicalBuildingObjectImplementation* _implementation = (MedicalBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISMEDICALBUILDINGOBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isMedicalBuildingObject();
}

DistributedObjectServant* MedicalBuildingObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void MedicalBuildingObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<MedicalBuildingObjectImplementation*>(servant));
}

/*
 *	MedicalBuildingObjectImplementation
 */

MedicalBuildingObjectImplementation::MedicalBuildingObjectImplementation(DummyConstructorParameter* param) : BuildingObjectImplementation(param) {
	_initializeImplementation();
}


MedicalBuildingObjectImplementation::~MedicalBuildingObjectImplementation() {
}


void MedicalBuildingObjectImplementation::finalize() {
}

void MedicalBuildingObjectImplementation::_initializeImplementation() {
	_setClassHelper(MedicalBuildingObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void MedicalBuildingObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MedicalBuildingObject*) stub;
	BuildingObjectImplementation::_setStub(stub);
}

DistributedObjectStub* MedicalBuildingObjectImplementation::_getStub() {
	return _this;
}

MedicalBuildingObjectImplementation::operator const MedicalBuildingObject*() {
	return _this;
}

Object* MedicalBuildingObjectImplementation::clone() {
	return dynamic_cast<Object*>(new MedicalBuildingObjectImplementation(*this));
}


void MedicalBuildingObjectImplementation::lock(bool doLock) {
}

void MedicalBuildingObjectImplementation::lock(ManagedObject* obj) {
}

void MedicalBuildingObjectImplementation::rlock(bool doLock) {
}

void MedicalBuildingObjectImplementation::wlock(bool doLock) {
}

void MedicalBuildingObjectImplementation::wlock(ManagedObject* obj) {
}

void MedicalBuildingObjectImplementation::unlock(bool doLock) {
}

void MedicalBuildingObjectImplementation::runlock(bool doLock) {
}

void MedicalBuildingObjectImplementation::_serializationHelperMethod() {
	BuildingObjectImplementation::_serializationHelperMethod();

	_setClassName("MedicalBuildingObject");

}

void MedicalBuildingObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(MedicalBuildingObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool MedicalBuildingObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuildingObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void MedicalBuildingObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = MedicalBuildingObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int MedicalBuildingObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + BuildingObjectImplementation::writeObjectMembers(stream);
}

MedicalBuildingObjectImplementation::MedicalBuildingObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/building/medical/MedicalBuildingObject.idl():  		Logger.setLoggingName("MedicalBuildingObject");
	Logger::setLoggingName("MedicalBuildingObject");
}

bool MedicalBuildingObjectImplementation::isMedicalBuildingObject() {
	// server/zone/objects/building/medical/MedicalBuildingObject.idl():  		return true;
	return true;
}

/*
 *	MedicalBuildingObjectAdapter
 */

MedicalBuildingObjectAdapter::MedicalBuildingObjectAdapter(MedicalBuildingObjectImplementation* obj) : BuildingObjectAdapter(obj) {
}

Packet* MedicalBuildingObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ISMEDICALBUILDINGOBJECT__:
		resp->insertBoolean(isMedicalBuildingObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool MedicalBuildingObjectAdapter::isMedicalBuildingObject() {
	return ((MedicalBuildingObjectImplementation*) impl)->isMedicalBuildingObject();
}

/*
 *	MedicalBuildingObjectHelper
 */

MedicalBuildingObjectHelper* MedicalBuildingObjectHelper::staticInitializer = MedicalBuildingObjectHelper::instance();

MedicalBuildingObjectHelper::MedicalBuildingObjectHelper() {
	className = "MedicalBuildingObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void MedicalBuildingObjectHelper::finalizeHelper() {
	MedicalBuildingObjectHelper::finalize();
}

DistributedObject* MedicalBuildingObjectHelper::instantiateObject() {
	return new MedicalBuildingObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* MedicalBuildingObjectHelper::instantiateServant() {
	return new MedicalBuildingObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MedicalBuildingObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MedicalBuildingObjectAdapter((MedicalBuildingObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


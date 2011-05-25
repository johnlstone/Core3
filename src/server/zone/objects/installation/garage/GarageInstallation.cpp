/*
 *	server/zone/objects/installation/garage/GarageInstallation.cpp generated by engine3 IDL compiler 0.60
 */

#include "GarageInstallation.h"

#include "server/zone/objects/area/ActiveArea.h"


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

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

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

#include "server/zone/objects/installation/HopperList.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/installation/SyncrhonizedUiListenInstallationTask.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/objects/resource/ResourceContainer.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/resource/SpawnMap.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/resource/ResourceSpawn.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "server/zone/objects/group/GroupObject.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/structure/events/StructureMaintenanceTask.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/structure/StructurePermissionList.h"

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

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	GarageInstallationStub
 */

enum {RPC_CREATECHILDOBJECTS__ = 6,RPC_DESTROYOBJECTFROMDATABASE__BOOL_};

GarageInstallation::GarageInstallation() : InstallationObject(DummyConstructorParameter::instance()) {
	GarageInstallationImplementation* _implementation = new GarageInstallationImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

GarageInstallation::GarageInstallation(DummyConstructorParameter* param) : InstallationObject(param) {
}

GarageInstallation::~GarageInstallation() {
}


void GarageInstallation::createChildObjects() {
	GarageInstallationImplementation* _implementation = (GarageInstallationImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATECHILDOBJECTS__);

		method.executeWithVoidReturn();
	} else
		_implementation->createChildObjects();
}

void GarageInstallation::destroyObjectFromDatabase(bool destroyContainedObjects) {
	GarageInstallationImplementation* _implementation = (GarageInstallationImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DESTROYOBJECTFROMDATABASE__BOOL_);
		method.addBooleanParameter(destroyContainedObjects);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyObjectFromDatabase(destroyContainedObjects);
}

DistributedObjectServant* GarageInstallation::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void GarageInstallation::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<GarageInstallationImplementation*>(servant));
}

/*
 *	GarageInstallationImplementation
 */

GarageInstallationImplementation::GarageInstallationImplementation(DummyConstructorParameter* param) : InstallationObjectImplementation(param) {
	_initializeImplementation();
}


GarageInstallationImplementation::~GarageInstallationImplementation() {
}


void GarageInstallationImplementation::finalize() {
}

void GarageInstallationImplementation::_initializeImplementation() {
	_setClassHelper(GarageInstallationHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void GarageInstallationImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GarageInstallation*) stub;
	InstallationObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GarageInstallationImplementation::_getStub() {
	return _this;
}

GarageInstallationImplementation::operator const GarageInstallation*() {
	return _this;
}

Object* GarageInstallationImplementation::clone() {
	return dynamic_cast<Object*>(new GarageInstallationImplementation(*this));
}


void GarageInstallationImplementation::lock(bool doLock) {
}

void GarageInstallationImplementation::lock(ManagedObject* obj) {
}

void GarageInstallationImplementation::rlock(bool doLock) {
}

void GarageInstallationImplementation::wlock(bool doLock) {
}

void GarageInstallationImplementation::wlock(ManagedObject* obj) {
}

void GarageInstallationImplementation::unlock(bool doLock) {
}

void GarageInstallationImplementation::runlock(bool doLock) {
}

void GarageInstallationImplementation::_serializationHelperMethod() {
	InstallationObjectImplementation::_serializationHelperMethod();

	_setClassName("GarageInstallation");

}

void GarageInstallationImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(GarageInstallationImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool GarageInstallationImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (InstallationObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "garageArea") {
		TypeInfo<ManagedReference<ActiveArea* > >::parseFromBinaryStream(&garageArea, stream);
		return true;
	}


	return false;
}

void GarageInstallationImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = GarageInstallationImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int GarageInstallationImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "garageArea";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ActiveArea* > >::toBinaryStream(&garageArea, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + InstallationObjectImplementation::writeObjectMembers(stream);
}

GarageInstallationImplementation::GarageInstallationImplementation() {
	_initializeImplementation();
	// server/zone/objects/installation/garage/GarageInstallation.idl():  		setLoggingName("ShuttleInstallation");
	setLoggingName("ShuttleInstallation");
}

/*
 *	GarageInstallationAdapter
 */

GarageInstallationAdapter::GarageInstallationAdapter(GarageInstallationImplementation* obj) : InstallationObjectAdapter(obj) {
}

Packet* GarageInstallationAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_CREATECHILDOBJECTS__:
		createChildObjects();
		break;
	case RPC_DESTROYOBJECTFROMDATABASE__BOOL_:
		destroyObjectFromDatabase(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void GarageInstallationAdapter::createChildObjects() {
	((GarageInstallationImplementation*) impl)->createChildObjects();
}

void GarageInstallationAdapter::destroyObjectFromDatabase(bool destroyContainedObjects) {
	((GarageInstallationImplementation*) impl)->destroyObjectFromDatabase(destroyContainedObjects);
}

/*
 *	GarageInstallationHelper
 */

GarageInstallationHelper* GarageInstallationHelper::staticInitializer = GarageInstallationHelper::instance();

GarageInstallationHelper::GarageInstallationHelper() {
	className = "GarageInstallation";

	Core::getObjectBroker()->registerClass(className, this);
}

void GarageInstallationHelper::finalizeHelper() {
	GarageInstallationHelper::finalize();
}

DistributedObject* GarageInstallationHelper::instantiateObject() {
	return new GarageInstallation(DummyConstructorParameter::instance());
}

DistributedObjectServant* GarageInstallationHelper::instantiateServant() {
	return new GarageInstallationImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GarageInstallationHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GarageInstallationAdapter((GarageInstallationImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


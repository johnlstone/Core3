/*
 *	server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "StartingLocationTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"


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

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

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
 *	StartingLocationTerminalStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_};

StartingLocationTerminal::StartingLocationTerminal() : Terminal(DummyConstructorParameter::instance()) {
	StartingLocationTerminalImplementation* _implementation = new StartingLocationTerminalImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

StartingLocationTerminal::StartingLocationTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

StartingLocationTerminal::~StartingLocationTerminal() {
}


void StartingLocationTerminal::initializeTransientMembers() {
	StartingLocationTerminalImplementation* _implementation = (StartingLocationTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

int StartingLocationTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	StartingLocationTerminalImplementation* _implementation = (StartingLocationTerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

DistributedObjectServant* StartingLocationTerminal::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void StartingLocationTerminal::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<StartingLocationTerminalImplementation*>(servant));
}

/*
 *	StartingLocationTerminalImplementation
 */

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}


StartingLocationTerminalImplementation::~StartingLocationTerminalImplementation() {
}


void StartingLocationTerminalImplementation::finalize() {
}

void StartingLocationTerminalImplementation::_initializeImplementation() {
	_setClassHelper(StartingLocationTerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void StartingLocationTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (StartingLocationTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* StartingLocationTerminalImplementation::_getStub() {
	return _this;
}

StartingLocationTerminalImplementation::operator const StartingLocationTerminal*() {
	return _this;
}

Object* StartingLocationTerminalImplementation::clone() {
	return dynamic_cast<Object*>(new StartingLocationTerminalImplementation(*this));
}


void StartingLocationTerminalImplementation::lock(bool doLock) {
}

void StartingLocationTerminalImplementation::lock(ManagedObject* obj) {
}

void StartingLocationTerminalImplementation::rlock(bool doLock) {
}

void StartingLocationTerminalImplementation::wlock(bool doLock) {
}

void StartingLocationTerminalImplementation::wlock(ManagedObject* obj) {
}

void StartingLocationTerminalImplementation::unlock(bool doLock) {
}

void StartingLocationTerminalImplementation::runlock(bool doLock) {
}

void StartingLocationTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("StartingLocationTerminal");

}

void StartingLocationTerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(StartingLocationTerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StartingLocationTerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TerminalImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void StartingLocationTerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StartingLocationTerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StartingLocationTerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TerminalImplementation::writeObjectMembers(stream);
}

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.idl():  		Logger.setLoggingName("StartingLocationTerminal");
	Logger::setLoggingName("StartingLocationTerminal");
}

/*
 *	StartingLocationTerminalAdapter
 */

StartingLocationTerminalAdapter::StartingLocationTerminalAdapter(StartingLocationTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* StartingLocationTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void StartingLocationTerminalAdapter::initializeTransientMembers() {
	((StartingLocationTerminalImplementation*) impl)->initializeTransientMembers();
}

int StartingLocationTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((StartingLocationTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

/*
 *	StartingLocationTerminalHelper
 */

StartingLocationTerminalHelper* StartingLocationTerminalHelper::staticInitializer = StartingLocationTerminalHelper::instance();

StartingLocationTerminalHelper::StartingLocationTerminalHelper() {
	className = "StartingLocationTerminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void StartingLocationTerminalHelper::finalizeHelper() {
	StartingLocationTerminalHelper::finalize();
}

DistributedObject* StartingLocationTerminalHelper::instantiateObject() {
	return new StartingLocationTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* StartingLocationTerminalHelper::instantiateServant() {
	return new StartingLocationTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StartingLocationTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StartingLocationTerminalAdapter((StartingLocationTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}


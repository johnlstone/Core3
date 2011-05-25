/*
 *	server/zone/objects/tangible/pharmaceutical/RevivePack.cpp generated by engine3 IDL compiler 0.60
 */

#include "RevivePack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


// Imported class dependencies

#include "system/util/Vector.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/group/GroupList.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "system/util/VectorMap.h"

#include "system/lang/Exception.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "system/net/SocketAddress.h"

#include "server/zone/ZoneProcessServer.h"

#include "system/net/Packet.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "engine/service/Message.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "engine/util/Observer.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/chat/ChatManager.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "system/net/Socket.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/login/account/Account.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/ZoneHandler.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	RevivePackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_GETHEALTHWOUNDHEALED__,RPC_GETHEALTHHEALED__,RPC_GETACTIONWOUNDHEALED__,RPC_GETACTIONHEALED__,RPC_GETMINDWOUNDHEALED__,RPC_GETMINDHEALED__,RPC_ISREVIVEPACK__};

RevivePack::RevivePack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	RevivePackImplementation* _implementation = new RevivePackImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

RevivePack::RevivePack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

RevivePack::~RevivePack() {
}


void RevivePack::updateCraftingValues(ManufactureSchematic* schematic) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void RevivePack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int RevivePack::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
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

float RevivePack::getHealthWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETHEALTHWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthWoundHealed();
}

float RevivePack::getHealthHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETHEALTHHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthHealed();
}

float RevivePack::getActionWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACTIONWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionWoundHealed();
}

float RevivePack::getActionHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACTIONHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionHealed();
}

float RevivePack::getMindWoundHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMINDWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindWoundHealed();
}

float RevivePack::getMindHealed() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMINDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindHealed();
}

bool RevivePack::isRevivePack() {
	RevivePackImplementation* _implementation = (RevivePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISREVIVEPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRevivePack();
}

DistributedObjectServant* RevivePack::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void RevivePack::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<RevivePackImplementation*>(servant));
}

/*
 *	RevivePackImplementation
 */

RevivePackImplementation::RevivePackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


RevivePackImplementation::~RevivePackImplementation() {
}


void RevivePackImplementation::finalize() {
}

void RevivePackImplementation::_initializeImplementation() {
	_setClassHelper(RevivePackHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void RevivePackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RevivePack*) stub;
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* RevivePackImplementation::_getStub() {
	return _this;
}

RevivePackImplementation::operator const RevivePack*() {
	return _this;
}

Object* RevivePackImplementation::clone() {
	return dynamic_cast<Object*>(new RevivePackImplementation(*this));
}


void RevivePackImplementation::lock(bool doLock) {
}

void RevivePackImplementation::lock(ManagedObject* obj) {
}

void RevivePackImplementation::rlock(bool doLock) {
}

void RevivePackImplementation::wlock(bool doLock) {
}

void RevivePackImplementation::wlock(ManagedObject* obj) {
}

void RevivePackImplementation::unlock(bool doLock) {
}

void RevivePackImplementation::runlock(bool doLock) {
}

void RevivePackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("RevivePack");

}

void RevivePackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RevivePackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RevivePackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "healthWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthWoundHealed, stream);
		return true;
	}

	if (_name == "healthHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthHealed, stream);
		return true;
	}

	if (_name == "actionWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionWoundHealed, stream);
		return true;
	}

	if (_name == "actionHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionHealed, stream);
		return true;
	}

	if (_name == "mindWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindWoundHealed, stream);
		return true;
	}

	if (_name == "mindHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindHealed, stream);
		return true;
	}


	return false;
}

void RevivePackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RevivePackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RevivePackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "healthWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "healthHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 6 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

RevivePackImplementation::RevivePackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		setLoggingName("RevivePack");
	setLoggingName("RevivePack");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthWoundHealed = 100;
	healthWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthHealed = 100;
	healthHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionWoundHealed = 100;
	actionWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionHealed = 100;
	actionHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindWoundHealed = 100;
	mindWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindHealed = 100;
	mindHealed = 100;
}

void RevivePackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float effectiveness = craftingValues.getCurrentValue("power");
	float effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		craftingValues.setHidden("power");
	craftingValues->setHidden("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float health = 2 * effectiveness;
	float health = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthWoundHealed = health;
	healthWoundHealed = health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthHealed = 2 * effectiveness - health;
	healthHealed = 2 * effectiveness - health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float action = 2 * effectiveness;
	float action = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		action = System.random(action / 4);
	action = System::random(action / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		action = action + effectiveness / 2;
	action = action + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionWoundHealed = action;
	actionWoundHealed = action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionHealed = 2 * effectiveness - action;
	actionHealed = 2 * effectiveness - action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float mind = 1.5 * effectiveness;
	float mind = 1.5 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mind = System.random(mind / 4);
	mind = System::random(mind / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mind = mind + effectiveness / 2;
	mind = mind + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindWoundHealed = mind;
	mindWoundHealed = mind;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindHealed = 1.5 * effectiveness - mind;
	mindHealed = 1.5 * effectiveness - mind;
}

void RevivePackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_health", Math.getPrecision(healthWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_health", Math::getPrecision(healthWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(healthHealed, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(healthHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_mind", Math.getPrecision(mindWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_mind", Math::getPrecision(mindWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_mind", Math.getPrecision(mindHealed, 0));
	msg->insertAttribute("examine_heal_damage_mind", Math::getPrecision(mindHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_action", Math.getPrecision(actionWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_action", Math::getPrecision(actionWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(actionHealed, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(actionHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("healing_ability", super.medicineUseRequired);
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::medicineUseRequired);
}

int RevivePackImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			string command = "/reviveplayer ";
	String command = "/reviveplayer ";
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 0;
	return 0;
}
}

float RevivePackImplementation::getHealthWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return healthWoundHealed;
	return healthWoundHealed;
}

float RevivePackImplementation::getHealthHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return healthHealed;
	return healthHealed;
}

float RevivePackImplementation::getActionWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return actionWoundHealed;
	return actionWoundHealed;
}

float RevivePackImplementation::getActionHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return actionHealed;
	return actionHealed;
}

float RevivePackImplementation::getMindWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return mindWoundHealed;
	return mindWoundHealed;
}

float RevivePackImplementation::getMindHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return mindHealed;
	return mindHealed;
}

bool RevivePackImplementation::isRevivePack() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return true;
	return true;
}

/*
 *	RevivePackAdapter
 */

RevivePackAdapter::RevivePackAdapter(RevivePackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* RevivePackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_GETHEALTHWOUNDHEALED__:
		resp->insertFloat(getHealthWoundHealed());
		break;
	case RPC_GETHEALTHHEALED__:
		resp->insertFloat(getHealthHealed());
		break;
	case RPC_GETACTIONWOUNDHEALED__:
		resp->insertFloat(getActionWoundHealed());
		break;
	case RPC_GETACTIONHEALED__:
		resp->insertFloat(getActionHealed());
		break;
	case RPC_GETMINDWOUNDHEALED__:
		resp->insertFloat(getMindWoundHealed());
		break;
	case RPC_GETMINDHEALED__:
		resp->insertFloat(getMindHealed());
		break;
	case RPC_ISREVIVEPACK__:
		resp->insertBoolean(isRevivePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RevivePackAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((RevivePackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

float RevivePackAdapter::getHealthWoundHealed() {
	return ((RevivePackImplementation*) impl)->getHealthWoundHealed();
}

float RevivePackAdapter::getHealthHealed() {
	return ((RevivePackImplementation*) impl)->getHealthHealed();
}

float RevivePackAdapter::getActionWoundHealed() {
	return ((RevivePackImplementation*) impl)->getActionWoundHealed();
}

float RevivePackAdapter::getActionHealed() {
	return ((RevivePackImplementation*) impl)->getActionHealed();
}

float RevivePackAdapter::getMindWoundHealed() {
	return ((RevivePackImplementation*) impl)->getMindWoundHealed();
}

float RevivePackAdapter::getMindHealed() {
	return ((RevivePackImplementation*) impl)->getMindHealed();
}

bool RevivePackAdapter::isRevivePack() {
	return ((RevivePackImplementation*) impl)->isRevivePack();
}

/*
 *	RevivePackHelper
 */

RevivePackHelper* RevivePackHelper::staticInitializer = RevivePackHelper::instance();

RevivePackHelper::RevivePackHelper() {
	className = "RevivePack";

	Core::getObjectBroker()->registerClass(className, this);
}

void RevivePackHelper::finalizeHelper() {
	RevivePackHelper::finalize();
}

DistributedObject* RevivePackHelper::instantiateObject() {
	return new RevivePack(DummyConstructorParameter::instance());
}

DistributedObjectServant* RevivePackHelper::instantiateServant() {
	return new RevivePackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RevivePackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RevivePackAdapter((RevivePackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

